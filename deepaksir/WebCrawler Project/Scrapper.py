# import tkinter as tk
import requests
from bs4 import BeautifulSoup
# import tabulate
# import matplotlib.pyplot as plt
# import webbrowser
data_of_all_good_products = []
header = { "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:109.0) Gecko/20100101 Firefox/119.0", 
           "Accept":"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,/;q=0.8"
            }
def good_product_amazon(product):
    if all([
        product.find("span", {"class": "a-text-normal"}) is not None,
        product.find("span", {"class": "a-offscreen"}) is not None,
        product.find("a", {"class": "a-link-normal"})["href"] is not None

    ]):
        return True

def good_product_flipkart(product):
    if all([
        product["product_name"] is not None,
        product["price"] is not None,
        product["url"] is not None,
        ]):
        return True

def extract_product_details(product,e):
    # Check the HTML structure and classes to determine the correct extraction method

    # print("product_name")
    # product_image_element = product.find("img", {"class": "_396cs4"})
    # product_image_link = product_image_element["src"] if product_image_element else product_image_element["data-src"]
    product_name = None
    product_price = None
    product_link = None

    
    if e==1:
        # print("&&")
        product_name = product.find("div", {"class": "_4rR01T"}).get_text(strip=True)
        product_price = product.find("div", {"class": "_30jeq3"}).get_text(strip=True)
        product_price = int(product_price.replace("₹", "").replace(",", ""))
        product_link= ("www.flipkart.com"+product.find("a",{"class": "_1fQZEK"})["href"]).split("&")[0]
    
    if e==2:
        # print("&&")
        product_name = product.find("a", {"class": "s1Q9rs"}).get_text(strip=True)
        product_price = product.find("div", {"class": "_30jeq3"}).get_text(strip=True)
        product_price = int(product_price.replace("₹", "").replace(",", ""))
        product_link = ("www.flipkart.com"+product.find("a",{"class": "_2rpwqI"})["href"]).split("&")[0]

    if e==3:
        # print("&&")
        product_name = product.find("a", {"class": "IRpwTa"}).get_text(strip=True)
        product_price = product.find("div", {"class": "_30jeq3"}).get_text(strip=True)
        product_price = int(product_price.replace("₹", "").replace(",", ""))
        product_link = ("www.flipkart.com"+product.find("a",{"class": "_2UzuFa"})["href"]).spilt("&")[0]


    data_of_good_product = {
        "product_name": product_name,
        "price": product_price,
        # "product_image_link": product_image_link,
        "url": product_link
    }
    e = 0
    if(good_product_flipkart(data_of_good_product)):
        data_of_all_good_products.append(data_of_good_product)
        return True
        # return data_of_good_product
    
    return False


def get_data_from_flipkart(user_input):
    url = f"https://www.flipkart.com/search?q={(user_input).replace(' ','%20')}"
    print(url)
    page = requests.get(url, headers=header)
    # print("scraping...(flipkart)")
    p=0
    while page.status_code != 200:
        page = requests.get(url, headers=header)
    soup = BeautifulSoup(page.text, "html.parser")
    # print(soup)
    e=0
    data_of_all_products= []
    if(data_of_all_products==[]):
        data_of_all_products = soup.find_all("div", class_= "_2kHMtA")
        # print(soup.find_all("div", class_= "_2kHMtA") )
        # print(data_of_all_products==[])
        e=1
    if(data_of_all_products==[]):
        data_of_all_products = soup.find_all("div", class_= "_4ddWXP")
        e=2
    if(data_of_all_products==[]):
        data_of_all_products = soup.find_all("div", class_= "_1xHGtK _373qXS")
        e=3

    # data_of_all_products = soup.find_all("div", class_= "_2kHMtA") + soup.find_all("div", class_= "_4ddWXP") + soup.find_all("div", class_= "_1xHGtK _373qXS")
    no = 0
    # print(data_of_all_products==[])
    # print(data_of_all_products[0].find("div", {"class" : "_2kHMtA"}))
    # print(extract_product_details(data_of_all_products[0]))
    for i in data_of_all_products:
        if extract_product_details(i,e) and no < 5:
            no+=1
            # print("1")
        if no >= 5:
            break

    # print(data_of_good_product)
    return data_of_all_good_products


def get_data_from_amazon(user_input):
    url = f"https://www.amazon.in/s?k={(user_input).replace(' ','+')}"
    print(url)
    page = requests.get(url, headers=header)
    # print("scraping...(amazon)")
    p=0
    while page.status_code != 200:
        p+=1
        print(p)
        page = requests.get(url, headers=header)
    
    # if not page.ok:
    #     return page.reason

    soup = BeautifulSoup(page.text, "html.parser")
    data_of_good_product = None
    data_of_all_products = soup.find_all("div", {"data-component-type": "s-search-result"})
    no = 0
    for i in data_of_all_products:
        if good_product_amazon(i) and no<5:
            no+=1
            product_name = i.find("span", {"class": "a-text-normal"}).get_text(strip=True)
            product_price = i.find("span", {"class": "a-offscreen"}).get_text(strip=True)
            product_price = int(float(product_price.replace("₹", "").replace(",", "")))
            product_link = "https://www.amazon.in" + i.find("a", {"class": "a-link-normal"})["href"]
            data_of_good_product = {
                "product_name": product_name,
                "price": product_price,
                "url": product_link
            }

            # print(data_of_good_product)
            data_of_all_good_products.append(data_of_good_product)
    # return data_of_all_good_products



user_input = input("Enter the product name: ")
print()
print("Scraping...")
get_data_from_flipkart(user_input)
print()
print("Scraping...")
get_data_from_amazon(user_input)

data_of_all_good_products.sort(key=lambda x: x["price"])

for i in data_of_all_good_products:
    print()
    print(i["product_name"])
    print(i["price"])
    print(i["url"])
    print()




# def plot_prices_with_links_and_tooltips(product_results, search_query):

#     product_names = [product_data.get("product_name")
#                      for product_data in product_results.values()]
#     product_prices = [product_data.get("product_price")
#                       for product_data in product_results.values()]
#     product_links = [product_data.get("product_link")
#                      for product_data in product_results.values()]
#     product_serials = list(product_results.keys())

#     x = list(range(1, len(product_names) + 1))

#     fig, ax = plt.subplots()

#     ax.plot(x, product_prices, marker='o', linestyle='-')
#     tooltips = []

#     buffer_x = 0.5
#     buffer_y = 100

#     def hover(event):
#         for tooltip in tooltips:
#             tooltip.set_visible(False)

#         for i, (xi, price, serial, name) in enumerate(zip(x, product_prices, product_serials, product_names)):
#             if event.xdata is not None and event.ydata is not None:
#                 if (xi - buffer_x) <= event.xdata <= (xi + buffer_x) and (price - buffer_y) <= event.ydata <= (price + buffer_y):
#                     tooltip_text = f"Serial: {serial}\nName: {name}\nPrice: ₹{price}"
#                     tooltip = ax.text(xi, price, tooltip_text, fontsize=8, ha='center', va='bottom', visible=True,
#                                       bbox=dict(boxstyle="round,pad=0.3", fc="white", ec="black"))
#                     tooltips.append(tooltip)

#         fig.canvas.draw_idle()

#     fig.canvas.mpl_connect('motion_notify_event', hover)

#     def on_click(event):
#         if event.xdata is not None and event.ydata is not None:
#             point_index = int(event.xdata) - 1
#             if 0 <= point_index < len(product_links):
#                 webbrowser.open(product_links[point_index])

#     fig.canvas.mpl_connect('button_press_event', on_click)

#     ax.set_xlabel("Products")
#     ax.set_ylabel("Price in ₹")
#     ax.set_title(f"Product Prices of search query: {search_query}")

#     plt.show()
# tabulate = tabulate.tabulate(data_of_all_good_products, headers="keys", tablefmt="latex")
# print(tabulate)

# def scrape_product():
#     # Get the user input from the product_entry widget
#     user_input = product_entry.get()
#     data_of_all_good_products = []
    
#     # Check if the user input is not empty
#     if user_input:
#         # Clear the result_label
#         result_label.config(text="Scraping...")

#         # call the search_amazon_by_product_name function
#         # product_details = get_data_from_amazon(user_input)
#         get_data_from_flipkart(user_input)
#         product_details = data_of_all_good_products

#         # Display the scraped data
#         result_label.config(text=product_details)
#     else:
#         result_label.config(text="Please enter a product name.")
#     pass
    
# Create the main application window
# root = tk.Tk()
# root.title("Product Price Comparison")

# # Create and place widgets (input fields, buttons, labels) in the window
# product_label = tk.Label(root, text="Enter Product:")
# product_label.pack()

# product_entry = tk.Entry(root)
# product_entry.pack()

# scrape_button = tk.Button(root, text="Scrape", command=scrape_product)
# scrape_button.pack()

# result_label = tk.Label(root, text="Scraped Data Will Appear Here")
# result_label.pack()

# # Start the GUI event loop
# root.mainloop()

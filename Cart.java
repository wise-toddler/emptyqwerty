// class Date
// {
//     // Date class
//     private int year;
//     private int month;
//     private int day;
//     // Getters and Setters
//     Date(String date)
//     {
//         String[] dateArray = date.split("-");
//         this.year = Integer.parseInt(dateArray[0]);
//         this.month = Integer.parseInt(dateArray[1]);
//         this.day = Integer.parseInt(dateArray[2]);
//     }
//     public String toString()
//     {
//         return year + "-" + month + "-" + day;
//     }  
// }
// import lombok.Getter;
// import lombok.Setter;

import java.util.ArrayList;

// @Getter
// @Setter
public class Cart {
    private Long id;
    private Long userId;
    private Date date;
    private ArrayList<ProductInCart> products;

    // make setter funtion for products

}
//
/*
 * {
 * id:1,
 * userId:1,
 * date:2020-10-10,
 * products:[{productId:2,quantity:4},{productId:1,quantity:10},{productId:5,
 * quantity:2}]
 * }
 * 
 * 
 */
//
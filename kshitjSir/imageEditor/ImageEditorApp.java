package imageEditor;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.*;
import javax.imageio.ImageIO;

public class ImageEditorApp {
    public JFrame frame;
    public JLabel imageLabel;
    public BufferedImage originalImage;
    public BufferedImage editedImage;

    public ImageEditorApp() 
    {
        // Create the main application window (JFrame)
        {
            frame = new JFrame("Image Editor");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(800, 600); // Set the initial size of the window
        }
        // Create a JLabel to display the edited image
        {
            imageLabel = new JLabel();
            frame.add(imageLabel, BorderLayout.CENTER); // Add the image label to the center of the frame
        }
        // Create the menu bar for the application
        {
            JMenuBar menuBar = new JMenuBar();
        
                // Create the "File" menu
                {
                    JMenu fileMenu = new JMenu("File");
                    JMenuItem openItem = new JMenuItem("Open Image");
                    openItem.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {
                            openImage(); // Define the action when "Open Image" is selected
                        }
                    });
                    fileMenu.add(openItem);

                    // Create a "Save Image" menu item
                    JMenuItem saveItem = new JMenuItem("Save Image");
                    saveItem.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {
                            saveImage();
                        }
                    });
                    fileMenu.add(saveItem); // Add the "Save Image" menu item to the "File" menu


                    menuBar.add(fileMenu);
                }
                // Create the "Edit" menu
                {
                    JMenu editMenu = new JMenu("Edit");
                    // Create menu items for various editing actions
                    // grayscaling
                    {
                        JMenuItem grayscaleItem = new JMenuItem("Grayscale");
                        grayscaleItem.addActionListener(new ActionListener() {
                            public void actionPerformed(ActionEvent e) {
                                convertToGrayScale(); // call the grayscale function
                            }
                        });editMenu.add(grayscaleItem);
                    }
                    // negative inverting
                    {
                        JMenuItem invertItem = new JMenuItem("Invert");
                        invertItem.addActionListener(new ActionListener() {
                            public void actionPerformed(ActionEvent e) {
                                invertImage(); // call the invert function
                            }
                        });editMenu.add(invertItem);
                    }
                    // brightness
                    {
                        JMenuItem brightnessItem = new JMenuItem("Change Brightness");
                        brightnessItem.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {
                            changeBrightness(); // call the brightness function
                        }
                        });editMenu.add(brightnessItem);
                    }
                    // blur
                    {
                        JMenuItem blurItem = new JMenuItem("Blur");
                        blurItem.addActionListener(new ActionListener() {
                            public void actionPerformed(ActionEvent e) {
                                applyBlur(); // call the blur function
                            }
                        });editMenu.add(blurItem);
                    
                    }
                    // flip
                    {
                        JMenu flipMenu = new JMenu("Flip");
                        JMenuItem horizontalItem = new JMenuItem("Horizontal");
                        JMenuItem verticalItem = new JMenuItem("Vertical");
                        // Add action listeners for the flip options
                        horizontalItem.addActionListener(new ActionListener() {
                            public void actionPerformed(ActionEvent e) {
                                flipImage("horizontal"); // Call the flipImage function with "horizontal" argument
                            }
                        });flipMenu.add(horizontalItem);
                        verticalItem.addActionListener(new ActionListener() {
                            public void actionPerformed(ActionEvent e) {
                                flipImage("vertical"); // Call the flipImage function with "vertical" argument
                            }
                        });flipMenu.add(verticalItem);
                        editMenu.add(flipMenu); 
                    }
                    // rotate
                    {    
                        JMenu rotItem = new JMenu("Rotate");
                        JMenuItem left = new JMenuItem("\u27F2");
                        JMenuItem right = new JMenuItem("\u27F3");
                        left.addActionListener(new ActionListener() {
                            public void actionPerformed(ActionEvent e) {
                                rotateImg("left"); // call the rotate function with "left" argument
                            }
                        });rotItem.add(left);
                        right.addActionListener(new ActionListener() {
                            public void actionPerformed(ActionEvent e) {
                                rotateImg("right"); // call the rotate function with "right" argument
                            }
                        });rotItem.add(right);
                        editMenu.add(rotItem); 
                    }
                    menuBar.add(editMenu); // Add the "Edit" menu to the menu bar
                }

            frame.setJMenuBar(menuBar); // Set the menu bar for the frame
        
            frame.setVisible(true); // Make the frame visible
        }
    }

    // save image function
    public void saveImage() {
        if (editedImage != null) {
            JFileChooser fileChooser = new JFileChooser();
            int result = fileChooser.showSaveDialog(frame);
            if (result == JFileChooser.APPROVE_OPTION) 
            {
                try
                {
                    File selectedFile = fileChooser.getSelectedFile();
                    String filePath = selectedFile.getAbsolutePath();
                    if (!filePath.toLowerCase().endsWith(".jpg")) {
                        selectedFile = new File(filePath + ".jpg"); // Append ".jpg" extension if not present
                    }
                    ImageIO.write(editedImage, "jpg", selectedFile); // Save as JPG format
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    // open image function
    public void openImage() {
        JFileChooser fileChooser = new JFileChooser();
        int result = fileChooser.showOpenDialog(frame);
        if (result == JFileChooser.APPROVE_OPTION) {
            try {
                File selectedFile = fileChooser.getSelectedFile();
                originalImage = ImageIO.read(selectedFile);
                editedImage = originalImage;
                displayImage(editedImage);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    // grayscale function
    public void convertToGrayScale()
    {
        int height=editedImage.getHeight();
        int width=editedImage.getWidth();
        BufferedImage outImg=new BufferedImage(width,height,BufferedImage.TYPE_BYTE_GRAY);
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
               outImg.setRGB(j,i,editedImage.getRGB(j,i));
        }
        editedImage=outImg;
        displayImage(editedImage);

    }
    
    // invert function
    public void invertImage()
    {
        int height=editedImage.getHeight();
        int width=editedImage.getWidth();
        BufferedImage outImg=new BufferedImage(width,height,BufferedImage.TYPE_3BYTE_BGR);
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
               outImg.setRGB(j,i,255-editedImage.getRGB(j,i));
        }
        editedImage=outImg;
        displayImage(editedImage);
    }

    // brightness function
    public void changeBrightness() {
        int height=editedImage.getHeight();
        int width=editedImage.getWidth();
        String brightness = JOptionPane.showInputDialog(frame, "Enter brightness adjustment (-100 to 100):");
        try {
            int adjustment = Integer.parseInt(brightness);
            if (adjustment < -100) {
                adjustment = -100;
            } else if (adjustment > 100) {
                adjustment = 100;
            }

            for (int x = 0; x < height; x++) {
                for (int y = 0; y < width; y++) 
                {
                    if(adjustment>=0)
                    {
                        Color pixel=new Color(editedImage.getRGB(y,x));
                        int red=pixel.getRed()+(255-pixel.getRed())*adjustment/100;
                        int green=pixel.getGreen()+(255-pixel.getGreen())*adjustment/100;
                        int blue=pixel.getBlue()+(255-pixel.getBlue())*adjustment/100;
                        pixel=new Color(red,green, blue);
                        editedImage.setRGB(y,x,pixel.getRGB()); 
                    }
                    else 
                    {
                        Color pixel=new Color(editedImage.getRGB(y,x));
                        int red=pixel.getRed()*(100+adjustment)/100;
                        int green=pixel.getGreen()*(100+adjustment)/100;
                        int blue=pixel.getBlue()*(100+adjustment)/100;
                        pixel=new Color(red,green, blue);
                        editedImage.setRGB(y,x,pixel.getRGB()); 
                    }
                }
            }
            displayImage(editedImage);
        } 
        catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Invalid input. Please enter a number.");
        }
        
    }

    // blur function
    public void applyBlur() 
    {
        // Prompt the user to enter the size of the blur box
        String blurBoxSize = JOptionPane.showInputDialog(frame, "Enter size of blur box (odd number): ");
        try {
            int n = Integer.parseInt(blurBoxSize);
            if (n % 2 == 0) {
                JOptionPane.showMessageDialog(frame, "Blur box size must be an odd number.");
                return; // Exit the function if the size is not odd
            }

            int m = n / 2;
            int width = editedImage.getWidth();
            int height = editedImage.getHeight();
            BufferedImage blurredImage = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);

            for (int x = 0; x < width; x++) 
            {
                for (int y = 0; y < height; y++) 
                {
                    int newRed = 0;
                    int newGreen = 0;
                    int newBlue = 0;

                    // Apply the box blur effect by averaging colors of adjacent pixels
                    for (int i = -m; i <= m; i++) 
                    {
                        for (int j = -m; j <= m; j++) 
                        {
                            if(i+x<0 || i+x>=width || j+y<0 || j+y>=height)
                                continue;
                            Color pixel = new Color(editedImage.getRGB(x + i, y + j));
                            newRed += pixel.getRed();
                            newGreen += pixel.getGreen();
                            newBlue += pixel.getBlue();
                        }
                    }

                    // Calculate the average color for the pixel
                    newRed /= (n * n);
                    newGreen /= (n * n);
                    newBlue /= (n * n);

                    blurredImage.setRGB(x, y, new Color(newRed, newGreen, newBlue).getRGB());
                }
            }
            editedImage = blurredImage;
            displayImage(editedImage);
        } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(frame, "Invalid input. Please enter a valid number.");
        }
    }

    // flip function
    public void rotateImg(String s)
    {
        int height=editedImage.getHeight();
        int width=editedImage.getWidth();
        BufferedImage outImg=new BufferedImage(height,width,BufferedImage.TYPE_3BYTE_BGR);
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
               outImg.setRGB(i,j,editedImage.getRGB(j,i));
        }
        editedImage=outImg;
        if(s.equals("left"))
            flipImage("vertical");
        else
            flipImage("horizontal");
    }

    // rotate function
    public void flipImage(String s)
    {
        int height=editedImage.getHeight();
        int width=editedImage.getWidth();
        if(s.equals("horizontal"))
        {
            for(int i=0;i<height;i++)
            {
                for(int j=0;j<width/2;j++)
                {
                    Color pixel=new Color(editedImage.getRGB(width-j-1,i));
                    editedImage.setRGB(width-j-1,i,editedImage.getRGB(j,i));
                    editedImage.setRGB(j,i,pixel.getRGB());
                }
            }
        }
        else
        {
            for(int j=0;j<width;j++)
            {
                for(int i=0;i<height/2;i++)
                {
                    Color pixel=new Color(editedImage.getRGB(j,height-i-1));
                    editedImage.setRGB(j,height-i-1,editedImage.getRGB(j,i));
                    editedImage.setRGB(j,i,pixel.getRGB());
                }
            }
        }
        displayImage(editedImage);
    }

    public void displayImage(BufferedImage image) {so by running one of the following commands sometime before
        hint: your next pull:
        hint: 
        hint:   git config pull.rebase false  # merge (the default strategy)
        hint:   git config pull.rebase true   # rebase
        hint:   git config pull.ff only       # fast-forward only
        hint: 
        hint: You can replace "git config" with "git config --global" to set a default
        hint: preference for all repositories. You can also pass --rebase, --no-rebase,
        hint: or --ff-only on the command line to override the configured default per
        hint: i
        ImageIcon icon = new ImageIcon(image);
        imageLabel.setIcon(icon);
        frame.pack();
    }

    public static void main(String[] args) {
        //sir ye toh mujhe khud nhi samj aaya aaphi bata dijiye kya h ye 
        // Use SwingUtilities.invokeLater to ensure GUI operations run on the EDT
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                // Create an instance of the ImageEditorApp class
                new ImageEditorApp();
            }
        });
    }
    
}
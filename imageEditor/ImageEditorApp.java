package imageEditor;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.awt.image.ColorModel;
import java.awt.image.WritableRaster;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class ImageEditorApp {
    public JFrame frame;
    public JLabel imageLabel;
    public BufferedImage originalImage;
    public BufferedImage editedImage;

    public ImageEditorApp() {
        // Create the main application window (JFrame)
        frame = new JFrame("Image Editor");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600); // Set the initial size of the window
    
        // Create a JLabel to display the edited image
        imageLabel = new JLabel();
        frame.add(imageLabel, BorderLayout.CENTER); // Add the image label to the center of the frame
    
        // Create the menu bar for the application
        JMenuBar menuBar = new JMenuBar();
    
        // Create the "File" menu
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
    
        // Create the "Edit" menu
        JMenu editMenu = new JMenu("Edit");
        // Create menu items for various editing actions
        JMenuItem grayscaleItem = new JMenuItem("Grayscale");
        grayscaleItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                convertToGrayScale(); // Define the action for applying grayscale
            }
        });
        editMenu.add(grayscaleItem);
    
        JMenuItem invertItem = new JMenuItem("Invert");
        invertItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                invertImage(); // Define the action for inverting colors
            }
        });
        editMenu.add(invertItem);
    
        JMenuItem brightnessItem = new JMenuItem("Change Brightness");
        brightnessItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                changeBrightness(); // Define the action for changing brightness
            }
        });
        editMenu.add(brightnessItem);
    
        JMenuItem blurItem = new JMenuItem("Blur");
        blurItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                applyBlur(); // Define the action for applying blur effect
            }
        });
        editMenu.add(blurItem);
    
        menuBar.add(editMenu); // Add the "Edit" menu to the menu bar
        frame.setJMenuBar(menuBar); // Set the menu bar for the frame
    
        frame.setVisible(true); // Make the frame visible
    }

    public void saveImage() {
        if (editedImage != null) {
            JFileChooser fileChooser = new JFileChooser();
            int result = fileChooser.showSaveDialog(frame);
            if (result == JFileChooser.APPROVE_OPTION) {
                try {
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

    public void openImage() {
        JFileChooser fileChooser = new JFileChooser();
        int result = fileChooser.showOpenDialog(frame);
        if (result == JFileChooser.APPROVE_OPTION) {
            try {
                File selectedFile = fileChooser.getSelectedFile();
                originalImage = ImageIO.read(selectedFile);
                editedImage = deepCopy(originalImage);
                displayImage(editedImage);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

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
                for (int y = 0; y < width; y++) {
                    Color pixel=new Color(editedImage.getRGB(y,x));
                    int red=pixel.getRed()+(255-pixel.getRed())*adjustment/100;
                    int green=pixel.getGreen()+(255-pixel.getGreen())*adjustment/100;
                    int blue=pixel.getBlue()+(255-pixel.getBlue())*adjustment/100;
                    pixel=new Color(red,green, blue);
                    editedImage.setRGB(y,x,pixel.getRGB());
                }
            }
            displayImage(editedImage);
        } 
        catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Invalid input. Please enter a number.");
        }
        
    }
    

    public int clamp(int value) {
        return Math.min(255, Math.max(0, value));
    }

    public void applyBlur() {
        if (editedImage != null) {
            int width = editedImage.getWidth();
            int height = editedImage.getHeight();
            BufferedImage blurredImage = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);

            for (int x = 1; x < width - 1; x++) {
                for (int y = 1; y < height - 1; y++) {
                    int newRed = 0;
                    int newGreen = 0;
                    int newBlue = 0;

                    // Apply the blur effect by averaging colors of adjacent pixels
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            int rgb = editedImage.getRGB(x + i, y + j);
                            newRed += (rgb >> 16) & 0xFF;
                            newGreen += (rgb >> 8) & 0xFF;
                            newBlue += rgb & 0xFF;
                        }
                    }

                    // Calculate the average color for the pixel
                    newRed /= 9;
                    newGreen /= 9;
                    newBlue /= 9;

                    blurredImage.setRGB(x, y, new Color(newRed, newGreen, newBlue).getRGB());
                }
            }

            // Update the editedImage with the blurredImage
            editedImage = blurredImage;
            displayImage(editedImage);
        }
    }

    public void displayImage(BufferedImage image) {
        ImageIcon icon = new ImageIcon(image);
        imageLabel.setIcon(icon);
        frame.pack();
    }

    public BufferedImage deepCopy(BufferedImage image) {
        ColorModel cm = image.getColorModel();
        boolean isAlphaPremultiplied = cm.isAlphaPremultiplied();
        WritableRaster raster = image.copyData(null);
        return new BufferedImage(cm, raster, isAlphaPremultiplied, null);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new ImageEditorApp();
            }
        });
    }
}



import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

class Bufferimg22Aug
{
    public static void printPixelValues(BufferedImage inImg)
    {
        int height=inImg.getHeight();
        int width=inImg.getWidth();
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                Color pixel=new Color(inImg.getRGB(j,i));
                System.out.print("("+pixel.getRed()+" "+pixel.getGreen()+" "+pixel.getBlue()+")");
            }
            System.out.println();
        }
    }
    public static BufferedImage convertToGrayScale(BufferedImage inImg)
    {
        int height=inImg.getHeight();
        int width=inImg.getWidth();
        BufferedImage outImg=new BufferedImage(width,height,BufferedImage.TYPE_BYTE_GRAY);
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
               outImg.setRGB(j,i,inImg.getRGB(j,i));
        }
        return outImg;

    }
    public static BufferedImage invertImage(BufferedImage inImg)
    {
        int height=inImg.getHeight();
        int width=inImg.getWidth();
        BufferedImage outImg=new BufferedImage(width,height,BufferedImage.TYPE_3BYTE_BGR);
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
               outImg.setRGB(j,i,255-inImg.getRGB(j,i));
        }
        return outImg;
    }

    public static BufferedImage incBright(BufferedImage inImg,int k)
    {
        int height=inImg.getHeight();
        int width=inImg.getWidth();
        BufferedImage outImg=new BufferedImage(width,height,BufferedImage.TYPE_3BYTE_BGR);
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                Color pixel=new Color(inImg.getRGB(j,i));
                int red=pixel.getRed()+(255-pixel.getRed())*k/100;
                int green=pixel.getGreen()+(255-pixel.getGreen())*k/100;
                int blue=pixel.getBlue()+(255-pixel.getBlue())*k/100;
                pixel=new Color(red,green, blue);
                outImg.setRGB(j,i,pixel.getRGB());
            }
        }
        return outImg;
    }
    public static void main(String[] args) throws IOException {
        // File inFile= new File("/home/user/Pictures/image.jpg");
        // BufferedImage inImg=ImageIO.read(inFile);
        BufferedImage inImg=ImageIO.read(new File("/home/user/Pictures/download.jpg"));
        // printPixelValues(inImg);
        // BufferedImage grayImg =convertToGrayScale(inImg);
        BufferedImage brigtImg =incBright(inImg,30);
        ImageIO.write(brigtImg,"jpg", new File("/home/user/Pictures/photobright.jpg"));

    }
}
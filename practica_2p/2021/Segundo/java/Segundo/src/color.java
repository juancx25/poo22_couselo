import java.text.DecimalFormat;
import java.util.Arrays;

public class color {
    private int color;
    public color(){
        this.color = 0;
    }
    public color(int color){
        this.color = color;
    }

    public int getAlpha(){ return (color&0xFF000000) >> 24; }
    public int getRed(){ return (color&0x00FF0000) >> 16; }
    public int getGreen(){ return (color&0x0000FF00) >> 8; }
    public int getBlue(){ return (color&0x000000FF); }
    public int getColor(){ return color; }

    //public void setAlpha(int alpha){ color = color & ; }
    //public void setRed(int red){ ; }
    //public void setGreen(int green){ ; }
    //public void setBlue(int blue){ ; }
    public void setColor(int color){ this.color = color; }
    @Override
    public String toString() {
        return ("A: "+getAlpha()+", R: "+getRed()+", G: "+getGreen()+", B: "+getBlue());
    }

}

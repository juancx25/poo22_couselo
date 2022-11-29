public abstract class figura implements FiguraMath{
    protected color fore_color;
    protected color back_color;
    protected double base;
    protected double altura;

    public figura(int fore_color, int back_color, double base, double altura){
        this.fore_color = new color(fore_color);
        this.back_color = new color(back_color);
        this.base = base;
        this.altura = altura;
    }

    public int getForeColor() { return fore_color.getColor(); }
    public int getBackColor() { return back_color.getColor(); }
    public double getBase(){ return this.base; }
    public double getAltura(){ return this.altura; }

    public void setForeColor(int fore_color){ this.fore_color = new color(fore_color); }
    public void setBackColor(int back_color){ this.back_color = new color(back_color); }
    public void setBase(double base){ this.base = base; }
    public void setAltura(double altura){ this.altura = altura; }

    public abstract void print();
    @Override
    public abstract String toString();

}

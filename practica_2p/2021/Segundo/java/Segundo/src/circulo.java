public class circulo extends figura {

    public circulo(int fore_color, int back_color, double base, double altura) {
        super(fore_color, back_color, base, 0);
    }

    public double area(){ return base*base*3.14; }
    public double perimetro(){ return 2*base*3.14; }

    public void print() {
        System.out.println("Soy un circulo con color " + fore_color + " sobre " + back_color);
        System.out.println("\tRadio = " + base + ", area = " + area() + " y perimetro = " + perimetro());
    }
    @Override
    public String toString() {
        return ("Circulo;"+this.getForeColor()+";"+this.getBackColor()+";"+this.base);
    }
}

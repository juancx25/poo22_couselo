public class triangulo extends figura {

    public triangulo(String tipo_figura, int fore_color, int back_color, double base, double altura) {
        super(tipo_figura, fore_color, back_color, base, altura);
    }

    public double area(){ return base*altura/2; }
    public double perimetro(){ return 3*base; }

    public void print(){
        System.out.println("Soy un triangulo con color "+fore_color+" sobre "+back_color);
        System.out.println("\tBase = "+base+", altura = "+altura+", area = "+area()+" y perimetro = "+perimetro());
    }

    @Override
    public String toString() {
        return ("Triangulo;"+this.getForeColor()+";"+this.getBackColor()+";"+this.base+";"+this.altura);
    }

}

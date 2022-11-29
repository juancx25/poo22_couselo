public class rectangulo extends figura{

    public rectangulo(String tipo_figura, int fore_color, int back_color, double base, double altura) {
        super(tipo_figura, fore_color, back_color, base, altura);
    }

    public double area(){ return base*altura; }
    public double perimetro(){ return (base+altura)*2; }

    public void print(){
        System.out.println("Soy un rectangulo con color "+fore_color+" sobre "+back_color);
        System.out.println("\tBase = "+base+", altura = "+altura+", area = "+area()+" y perimetro = "+perimetro());
    }

    @Override
    public String toString() {
        return ("Rectangulo;"+this.getForeColor()+";"+this.getBackColor()+";"+this.base+";"+this.altura);
    }

}

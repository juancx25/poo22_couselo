public class rectangulo extends figura implements IFigura {
    double base;
    double altura;

    public double getBase(){ return this.base; }
    public double getAltura(){ return this.altura; }

    public rectangulo(double base,double altura){
        this.lados = 4;
        //this.color = [0,0,0,0];
        this.base = base;
        this.altura = altura;
    }

    @Override
    public double area() {
        return (base*altura);
    }

    @Override
    public String colorInfo() {
        return null;
    }
}

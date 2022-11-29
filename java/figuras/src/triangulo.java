public class triangulo extends figura {

    double base;
    double altura;

    public triangulo(){
        this.lados = 3;
        //this.color = [0,0,0,0];
        this.base = 0;
        this.altura = 0;
    }

    public double getBase(){ return this.base; }
    public double getAltura(){ return this.altura; }

    public triangulo(double base,double altura){
        this.lados = 3;
        //this.color = [0,0,0,0];
        this.base = base;
        this.altura = altura;
    }

    public double area(){
        return ((base*altura)/2);
    }

    public String colorInfo(){
        return "";
    }
}

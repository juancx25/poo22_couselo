import java.io.Serializable;

public class pepe implements Serializable {

    private static final long serialVersionUID = 1L;

    public pepe_chiquito chiquilin;
    public String str;
    public int entero;
    public char caracter;
    public boolean bool1;
    public boolean bool2;
    public boolean bool3;
    public boolean bool4;

    public pepe(){
        this.chiquilin = new pepe_chiquito();
        this.str = "";
        this.entero = 0;
        this.caracter = 0;
        this.bool1 = false;
        this.bool2 = false;
        this.bool3 = false;
        this.bool4 = false;
    }
}
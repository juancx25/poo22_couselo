import java.io.Serializable;
public class pepe_chiquito implements Serializable {
    private static final long serialVersionUID = 1L;
    public int entero_chiquito;
    public char char_chiquito;

    public pepe_chiquito(){
        entero_chiquito = 0;
        char_chiquito = 0;
    }
    public pepe_chiquito(int v,char c){
        entero_chiquito = v;
        char_chiquito = c;
    }
}

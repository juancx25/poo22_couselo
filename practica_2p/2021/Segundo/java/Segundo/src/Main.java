import java.io.IOException;
import java.text.DecimalFormat;

public class Main {

    public static void main(String[] args) throws IOException {

        ManejadorFiguras mf = new ManejadorFiguras();
        //mf.recuperarFiguras("figuras_entrada.txt");
        mf.recuperarFiguras_bin("figuras_salida.bin");
        mf.print();
        //mf.guardarFiguras("figuras_salida.txt");
        //mf.guardarFiguras_bin("figuras_salida.bin");

        mf.ordenar("figuras_area.txt","area");
        mf.ordenar("figuras_perimetro.txt","perimetro");
    }
}
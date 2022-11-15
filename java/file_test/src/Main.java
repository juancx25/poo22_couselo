import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        //employee pepe = new employee("Jose","Fierro",3,2,1966,1234,false);
        employee pepe = new employee();
        employee jose = new employee();
        try{
            pepe.importar_empleado_txt("pepe.txt");

            pepe.imprimir();
            //jose.exportar_empleado_bin("pepe.bin");
            pepe.exportar_empleado_txt("pepe.txt");
        }catch (IOException e){
            System.out.println("AAAAAAAAAAAAAAAAA");
        }

    }
}
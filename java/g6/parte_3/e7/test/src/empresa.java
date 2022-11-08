import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class empresa extends persona {

    protected ArrayList<persona> empleados;

    // Esto es redundante??
    public empresa(){
        empleados = new ArrayList<persona>();
    }

    public void agregar_empleado(){
        persona e = new persona();
        // persona e = persona(); Sin el new también "funciona". Qué diferencia hay? e es una referencia si uso new?
        e.insert();

        empleados.add(e);

    }

    public void agregar_empleado(String n, String a){
        persona e = new persona(n,a);
        empleados.add(e);
    }

    public void imprimir_empleados(){
        if (empleados.isEmpty()){
            System.out.println("No hay empleados");
        }else{
            System.out.println("Lista de empleados:");
            for (persona p : empleados){
                System.out.println(p.getApellido() + ", " + p.getNombre());
            }
        }
    }

    public void importar_empleados(String fname) throws IOException {

        String line = "";
        BufferedReader br = new BufferedReader(new FileReader(fname));

        while ((line = br.readLine()) != null){
            String[] aux = line.split(",");
            persona e = new persona(aux[0],aux[1]);
            empleados.add(e);
        }
        br.close();
    }

    public void exportar_empleados(String fname) throws IOException {

        PrintWriter out = new PrintWriter(fname);

        for (persona p : empleados){
            out.println(p.getNombre()+","+p.getApellido());
        }
        out.close();
    }
}

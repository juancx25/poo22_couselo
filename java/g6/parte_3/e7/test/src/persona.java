import java.util.Scanner;

public class persona {
    private String nombre;
    private String apellido;

    public persona(String n,String a){
        nombre = n;
        apellido = a;
    }
    public persona(){
        nombre = "";
        apellido = "";
    }

    public void insert(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Nombre: ");
        String n = scanner.nextLine();
        System.out.println("Apellido: ");
        String a = scanner.nextLine();
        nombre = n;
        apellido = a;
        //scanner.close();
    }

    public String getNombre(){ return nombre; }
    public String getApellido(){ return apellido; }

    public void setNombre(String n){ nombre = n; }
    public void setApellido(String a){ apellido = a; }
}

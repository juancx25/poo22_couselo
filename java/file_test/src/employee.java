import java.io.*;

public class employee {
    private String first_name;
    private String last_name;
    private date birth_date;
    private int employee_number;
    private boolean married;

    public employee(String first_name, String last_name, date birth_date, int employee_number, boolean is_married){
        this.first_name = first_name;
        this.last_name = last_name;
        this.birth_date = birth_date;
        this.employee_number = employee_number;
        this.married = is_married;
    }
    public employee(String first_name, String last_name, int day,int month,int year, int employee_number, boolean is_married){
        this.first_name = first_name;
        this.last_name = last_name;
        this.birth_date = new date(day,month,year);
        this.employee_number = employee_number;
        this.married = is_married;
    }

    public employee() {
        this.first_name = "";
        this.last_name = "";
        this.birth_date = new date();
        this.employee_number = 0;
        this.married = false;
    }

    public String getFirst_name(){ return this.first_name; }
    public String getLast_name(){ return this.last_name; }
    public date getBirth_date(){ return this.birth_date; }
    public int getEmployee_number(){ return this.employee_number; }
    public boolean isMarried(){ return this.married; }

    public void setFirst_name(String first_name){ this.first_name = first_name; }
    public void setLast_name(String last_name){ this.last_name = last_name; }
    public void setBirth_date(int day,int month, int year){ this.birth_date = new date(day,month,year); }
    public void setEmployee_number(int employee_number){ this.employee_number = employee_number; }
    public void setMarried(boolean married){ this.married = married; }

    public void imprimir(){
        System.out.println("Nombre: "+first_name);
        System.out.println("Apellido: "+last_name);
        System.out.print("Fecha de nacimiento: ");birth_date.imprimir();
        System.out.println();
        System.out.println("Num. empleado: "+employee_number);
        System.out.println("Casado?: "+married);

    }

    public void importar_empleado_txt(String file_name) throws IOException{
        String line = "";
        BufferedReader br = new BufferedReader(new FileReader(file_name));
        while ((line = br.readLine()) != null){
            String[] aux = line.split(",");
            this.first_name = aux[0];
            this.last_name = aux[1];
            this.birth_date = new date(Integer.parseInt(aux[2]),Integer.parseInt(aux[3]),Integer.parseInt(aux[4]));
            this.employee_number = Integer.parseInt(aux[5]);
            this.married = Boolean.parseBoolean(aux[6]);
        }

        br.close();
    }
    public void exportar_empleado_txt(String file_name) throws IOException {
        PrintWriter out = new PrintWriter(file_name);
        out.println(first_name+','+last_name+','+birth_date.aString()+','+Integer.toString(employee_number)+','+married);
        out.close();
    }

    public void exportar_empleado_bin(String file_name) throws IOException {
        FileOutputStream fos = new FileOutputStream(file_name);
        DataOutputStream dos = new DataOutputStream(fos);
        int aux;
        aux = first_name.length();
        dos.writeInt(aux);
        fos.write(first_name.getBytes());

    }
    public void importar_empleado_bin(String file_name) throws IOException {
        FileInputStream fis = new FileInputStream(file_name);

    }
}


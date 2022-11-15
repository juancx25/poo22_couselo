public class date {
    private int day;
    private int month;
    private int year;

    public date(){
        this.day = 1;
        this.month = 1;
        this.year = 1970;
    }
    public date(int day, int month, int year){
        this.day = day;
        this.month = month;
        this.year = year;
    }
    public int getDay(){ return this.day; }
    public int getMonth(){ return this.month; }
    public int getYear(){ return this.year; }

    public void setDay(int day){ this.day = day; }
    public void setMonth(int month){ this.month = month; }
    public void setYear(int year){ this.year = year; }
}

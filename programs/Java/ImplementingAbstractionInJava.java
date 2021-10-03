import java.util.*;

abstract class Book{
    String title;
    abstract void setTitle(String s);
    String getTitle(){
        return title;
    }
}

class Child extends Book {

    void setTitle(String s) {
        title = s;
    }
}

public class Main{
    
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        String get_title = sc.nextLine();
        Child obj = new Child();
        obj.setTitle(get_title);
        System.out.println("The title is: "+obj.getTitle());
          sc.close();
        
    }
}

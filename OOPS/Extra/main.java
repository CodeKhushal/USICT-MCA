class Box{
    double length;
    double width;
    Box(){
        length = 0;
        width = 0;
    }

    Box(double length, double width){
        this.length = length;
        this.width = width;
    }

    public void display(String boxName){
        System.out.println("Length of " + boxName +": "+ this.length);
        System.out.println("Width of " + boxName +": "+ this.width + '\n');
    }

    public double area(){
        return length*width;
    }
}


class BoxWeight extends Box{
    double height;
    BoxWeight(){
        super();
        this.height = 0;
    }
    BoxWeight(double length, double width, double height){
        super(length, width);
        this.height = height;
    }

    public void display(String boxName){
        System.out.println("Length of " + boxName +": "+ this.length);
        System.out.println("Width of " + boxName +": "+ this.width);
        System.out.println("Height of " + boxName +": "+ this.height + '\n');
    }

    public double volume(){
        return length*width*height;
    }
}

class main {
    public static void main(String[] args){
        Box box1 = new Box();
        Box box2 = new Box(5,6);
        box1.display("Box1");
        box2.display("Box2");
        System.out.println("Area of Box1: " + box1.area());
        System.out.println("Area of Box2: " + box2.area());

        System.err.println("\n--------------------------\n");

        BoxWeight box3 = new BoxWeight();
        BoxWeight box4 = new BoxWeight(5,6,7);
        box3.display("Box3");
        box4.display("Box4");
        System.out.println("Volume of Box3: " + box3.volume());
        System.out.println("Volume of Box4: " + box4.volume());
    }
}
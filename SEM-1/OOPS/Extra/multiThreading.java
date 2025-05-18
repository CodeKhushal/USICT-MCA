class A extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("i: " + i);
        }
    }
}

class B extends Thread {
    public void run() {
        for (int j = 1; j <= 5; j++) {
            System.out.println("j: " + j);
        }
    }
}

class C extends Thread {
    public void run() {
        for (int k = 1; k <= 5; k++) {
            System.out.println("k: " + k);
        }
    }
}

class multiThreading {
    public static void main(String[] args) {
        A o1 = new A();
        B o2 = new B();
        C o3 = new C();

        o1.start();
        o2.start();
        o3.start();
    }
}
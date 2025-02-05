public class q9MainThread {
    public static void performOperations() {
        System.out.println("\nMain thread is performing operations:");
        for (int i = 1; i <= 5; i++) {
            System.out.println("Performing task " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Thread was interrupted.");
            }
        }

        System.out.println("Main thread operations completed.");
    }

    public static void main(String[] args) {
        Thread mainThread = Thread.currentThread();
        System.out.println("Main Thread Name: " + mainThread.getName());
        System.out.println("Main Thread Priority: " + mainThread.getPriority());

        mainThread.setName("Khushal Thread One");
        mainThread.setPriority(Thread.MAX_PRIORITY);

        System.out.println("\nUpdated Main Thread Name: " + mainThread.getName());
        System.out.println("Updated Main Thread Priority: " + mainThread.getPriority());
        
        performOperations();
        System.out.println("\nThread Name: " + mainThread.getName());
        System.out.println("Thread Priority: " + mainThread.getPriority());
    }
}

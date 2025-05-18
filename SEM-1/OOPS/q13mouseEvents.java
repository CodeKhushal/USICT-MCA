import javax.swing.*;
import java.awt.event.*;

public class q13mouseEvents extends JFrame {
    public q13mouseEvents() {
        setTitle("Mouse Events");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                System.out.println("Mouse clicked at: " + e.getX() + ", " + e.getY());
            }

            @Override
            public void mousePressed(MouseEvent e) {
                System.out.println("Mouse pressed at: " + e.getX() + ", " + e.getY());
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                System.out.println("Mouse released at: " + e.getX() + ", " + e.getY());
            }

            @Override
            public void mouseEntered(MouseEvent e) {
                System.out.println("Mouse entered the window.");
            }

            @Override
            public void mouseExited(MouseEvent e) {
                System.out.println("Mouse exited the window.");
            }
        });
        addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                System.out.println("Mouse dragged at: " + e.getX() + ", " + e.getY());
            }
            @Override
            public void mouseMoved(MouseEvent e) {
                System.out.println("Mouse moved at: " + e.getX() + ", " + e.getY());
            }
        });
    }

    public static void main(String[] args) {    
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new q13mouseEvents().setVisible(true);
            }
        });
    }
}

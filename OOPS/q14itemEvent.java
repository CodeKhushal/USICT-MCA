import java.awt.*;
import java.awt.event.*;

class ChildFrame extends Frame {

    public ChildFrame(String name) {
        setTitle(name + " Frame");
        setSize(300, 150);
        setLayout(new FlowLayout());

        Label label = new Label("This is a " + name + " frame.");
        label.setName("childFrameLabel");
        add(label);

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent we) {
                setVisible(false);
            }
        });
    }
}

public class q14itemEvent extends Frame {
    String selectedItem;
    public q14itemEvent() {
        setTitle("Item Event Choice");
        setLayout(new FlowLayout());
        setSize(400, 200);

        Choice choice = new Choice();
        choice.setName("choiceComponent");
        choice.add("OOPS");
        choice.add("DBMS");
        choice.add("DSA");
        choice.add("Software Engineering");

        selectedItem = choice.getItem(0);
        add(choice);

        choice.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                selectedItem = choice.getSelectedItem();
                System.out.println("Selected item: " + selectedItem);
            }
        });

        Button openChildFrameButton = new Button("Open Child Frame");
        openChildFrameButton.setName("openChildFrameButton");
        add(openChildFrameButton);

        openChildFrameButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                selectedItem = choice.getSelectedItem();
                ChildFrame childFrame = new ChildFrame(selectedItem);
                childFrame.setVisible(true);
            }
        });

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        q14itemEvent mainFrame = new q14itemEvent();
        mainFrame.setVisible(true);
    }
}

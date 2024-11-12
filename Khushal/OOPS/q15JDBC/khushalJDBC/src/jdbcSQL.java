import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class jdbcSQL {
    public static void main(String[] args) {
        String jdbcUrl = "jdbc:mysql://localhost:3306/universitydb";
        String username = "root";
        String password = "1234";

        try (Connection connection = DriverManager.getConnection(jdbcUrl, username, password);
                Statement statement = connection.createStatement()) {

            System.out.println("Connected to the database.");

            String query = "SELECT * FROM student";
            ResultSet resultSet = statement.executeQuery(query);

            while (resultSet.next()) {
                int id = resultSet.getInt("stud_id");
                String f_name = resultSet.getString("f_name");
                String l_name = resultSet.getString("l_name");
                System.out.println("ID: " + id + ", First Name: " + f_name + ", Last Name: " + l_name);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

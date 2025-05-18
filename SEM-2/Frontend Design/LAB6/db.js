const express = require("express");
const mongoose = require("mongoose");
const app = express();

mongoose
  .connect("mongodb://localhost:27017/userDB", {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  })
  .then(() => console.log("Connected to MongoDB"))
  .catch((err) => console.error("Error connecting to MongoDB:", err));

const userSchema = new mongoose.Schema({
  name: String,
  email: String,
});

const User = mongoose.model("User", userSchema);

app.get("/create", async (req, res) => {
  const user = new User({ name: "Khushal Sachdeva", email: "khushal@gmail.com" });
  await user.save();
  res.send("User created!");
});

app.get("/user", async (req, res) => {
  const user = await User.findOne({ email: "khushal@gmail.com" });
  if (user) {
    res.send(`User found: ${user.name} - ${user.email}`);
  } else {
    res.send("User not found");
  }
});

app.get("/", (req, res) => {
  res.send("Hello, World!");
});

const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});

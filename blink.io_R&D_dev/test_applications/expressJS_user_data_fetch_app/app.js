const express = require('express');
const axios = require('axios');
const path = require('path');
const app = express();

// Serve static files (like HTML, CSS)
app.use(express.static(path.join(__dirname, 'public')));

// Parse URL-encoded bodies (for form submissions)
app.use(express.urlencoded({ extended: true }));

// Route to serve the HTML file
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

// Route to fetch user data from external API
app.post('/fetch-user', async (req, res) => {
  const userId = req.body.userId; // Get the user ID from the form

  try {
    const response = await axios.get(`https://jsonplaceholder.typicode.com/users/${userId}`);
    const userData = response.data;

    // Send the user data back to the frontend as JSON
    res.json(userData);
  } catch (error) {
    res.status(404).json({ error: 'User not found' });
  }
});

// Start the server
const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});

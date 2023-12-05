const express = require('express');
const bodyParser = require('body-parser');
const { spawn } = require('child_process');
const cors = require('cors');

const app = express();
const port = 5000;

app.use(bodyParser.json());
app.use(cors());

app.post('/api/calculate', (req, res) => {
  const { month, duration, age, gender, accommodation, budget } = req.body;
  const dataStructure = req.query.dataStructure;

  const process = spawn('cpp/main.out', [dataStructure, month, duration, age, gender, accommodation, budget]);

  let responseData = '';

  process.stdout.on('data', (data) => {
    responseData += data.toString(); // Collect data from stdout
  });

  process.stderr.on('data', (data) => {
    console.error(`Error: ${data}`);
    responseData = 'Internal Server Error'; // Set error message
  });

  process.on('close', (code) => {
    if (code === 0) {
      // The child process executed successfully
      const result = responseData.trim();
      res.json({ result });
    } else {
      // There was an error in the child process
      res.status(500).json({ error: responseData.trim() || 'Internal Server Error' });
    }
  });
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});

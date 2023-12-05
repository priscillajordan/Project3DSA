import React, { useState } from 'react';
import { Button, TextField, Typography, Select, MenuItem, InputLabel, FormControl } from '@mui/material';

const months = [
  'January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'
];
const genders = ['Male', 'Female'];
const accommodations = ['Hotel', 'Resort', 'Airbnb', 'Villa', 'Vacation Rental', 'Hostel', 'Eco-Lodge'];

const App: React.FC = () => {
  const [month, setMonth] = useState<string>('');
  const [duration, setDuration] = useState<string>('');
  const [age, setAge] = useState<string>('');
  const [gender, setGender] = useState<string>('');
  const [accommodation, setAccommodation] = useState<string>('');
  const [budget, setBudget] = useState<string>('');
  const [result, setResult] = useState<string>('');

  const handleSubmit = async (dataStructure: string) => {
    try {
      const response = await fetch(`http://localhost:5000/api/calculate?dataStructure=${dataStructure}`, {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          dataStructure,
          month,
          duration,
          age,
          gender,
          accommodation,
          budget,
        }),
      });

      if (!response.ok) {
        throw new Error(`HTTP error! Status: ${response.status}`);
      }

      const data = await response.json();
      setResult(data.result);
    } catch (error: any) {
      console.error('Error submitting data:', error.message);
    }
  };

  return (
    <div style={{ padding: 50 }}>
       <Typography variant="h3" style={{ marginTop: 20 }}>
          Tell us a bit about yourself and your vacation preferences!
        </Typography>
      <FormControl fullWidth margin="normal">
        <InputLabel id="month-label">Month</InputLabel>
        <Select
          labelId="month-label"
          id="month"
          value={month}
          label="Month"
          onChange={(e) => setMonth(e.target.value as string)}
        >
          {months.map((m) => (
            <MenuItem key={m} value={m}>
              {m}
            </MenuItem>
          ))}
        </Select>
      </FormControl>

      <TextField
      margin="normal"
        label="Duration"
        type="text"
        value={duration}
        onChange={(e) => setDuration(e.target.value)}
      />

      <TextField
      margin="normal"
        label="Age"
        type="text"
        value={age}
        onChange={(e) => setAge(e.target.value)}
      />

      <FormControl fullWidth margin="normal">
        <InputLabel id="gender-label">Gender</InputLabel>
        <Select
          labelId="gender-label"
          id="gender"
          value={gender}
          label="Gender"
          onChange={(e) => setGender(e.target.value as string)}
        >
          {genders.map((g) => (
            <MenuItem key={g} value={g}>
              {g}
            </MenuItem>
          ))}
        </Select>
      </FormControl>

      <FormControl fullWidth margin="normal">
        <InputLabel id="accommodation-label">Accommodation</InputLabel>
        <Select
          labelId="accommodation-label"
          id="accommodation"
          value={accommodation}
          label="Accommodation"
          onChange={(e) => setAccommodation(e.target.value as string)}
        >
          {accommodations.map((a) => (
            <MenuItem key={a} value={a}>
              {a}
            </MenuItem>
          ))}
        </Select>
      </FormControl>

      <TextField
      margin="normal"
        label="Budget"
        type="text"
        value={budget}
        onChange={(e) => setBudget(e.target.value)}
      />

      <div style={{ marginTop: 20 }}>
        <Button
          variant="contained"
          color="primary"
          onClick={() => handleSubmit('hashmap')}
          style={{ marginRight: 10 }}
        >
          Use Hashmap
        </Button>

        <Button
          variant="contained"
          color="primary"
          onClick={() => handleSubmit('minheap')}
        >
          Use Minheap
        </Button>
      </div>

      {result && (
        <Typography variant="h6" style={{ marginTop: 50 }}>
        {result}
        </Typography>
      )}
    </div>
  );
};

export default App;

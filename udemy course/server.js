const express = require('express');
const app = express() 

app.use(express.static('public'));
app.use(express.static('lib'));

app.listen(8080, () => console.log("start that shit"))
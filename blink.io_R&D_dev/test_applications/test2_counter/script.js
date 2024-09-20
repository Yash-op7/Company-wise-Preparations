const output = document.getElementById('count-value');;
const btn = document.getElementById('button');

let count = 0;
btn.addEventListener('click', () => output.innerHTML = ++count)
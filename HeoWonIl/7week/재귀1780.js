const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const n = Number(input[0]);
const paper = input.slice(1).map((v) => v.split(" ").map(Number));

let answer = [0, 0, 0];

function recursion(row, col, n) {
  const color = paper[row][col];

  for (let i = row; i < row + n; i++) {
    for (let j = col; j < col + n; j++) {
      if (color !== paper[i][j]) {
        for (let k = 0; k < 3; k++) {
          for (let s = 0; s < 3; s++) {
            recursion(row + (n / 3) * k, col + (n / 3) * s, n / 3);
          }
        }
        return;
      }
    }
  }

  if (color === -1) {
    answer[0]++;
  }
  if (color === 0) {
    answer[1]++;
  }
  if (color === 1) {
    answer[2]++;
  }
}

recursion(0, 0, n);
console.log(answer[0]);
console.log(answer[1]);
console.log(answer[2]);

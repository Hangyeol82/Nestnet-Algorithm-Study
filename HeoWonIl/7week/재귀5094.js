// 풀이 출처: https://velog.io/@nullyng/%EB%B0%B1%EC%A4%80%EA%B3%A8%EB%93%9C5-Moo-%EA%B2%8C%EC%9E%84-javascript
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const N = +fs.readFileSync(filePath).toString().trim();

const solution = (N) => {
  let totalLength = 0;
  let temp = 3; // o가 k+2개인 수열의 길이

  while (1) {
    totalLength = totalLength * 2 + temp;
    if (totalLength >= N) break;
    temp++;
  }

  while (1) {
    let prevLength = ~~((totalLength - temp) / 2);

    if (N <= prevLength) {
      // N이 앞쪽 수열에 해당하는 경우
      totalLength = prevLength;
      temp--;
    } else if (prevLength < N && N <= prevLength + temp) {
      // N이 o가 k+2개인 수열에 해당하는 경우
      if (N - prevLength === 1) console.log("m");
      else console.log("o");
      break;
    } else if (prevLength + temp < N) {
      // N이 뒤쪽 수열에 해당하는 경우
      N -= prevLength + temp;
      totalLength = prevLength;
      temp--;
    }
  }
};

solution(N);

// 오답 풀이
// const fs = require("fs");
// const stdin = fs.readFileSync("dev/stdin").toString().split("\n");
// const input = (() => {
//   let line = 0;
//   return () => stdin[line++];
// })();

// const N = Number(input());
// function recursion(k) {
//   if (k == 0) return "moo";
//   return recursion(k - 1) + "m" + "o".repeat(k + 2) + recursion(k - 1);
// }

// function countM(k) {
//   if (k == 0) return 1;
//   return countM(k - 1) * 2 + 1;
// }
// function countO(k) {
//   if (k == 0) return 2;
//   return countO(k - 1) * 2 + (k + 2);
// }

// let k = 0;
// while (true) {
//   const cnt = countM(k) + countO(k);
//   if (cnt >= N) {
//     const answer = recursion(k);
//     console.log(answer[N - 1]);
//     break;
//   }
//   k++;
// }

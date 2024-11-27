const fs = require("fs");
const stdin = fs.readFileSync("/dev/stdin").toString().split("\n");
const input = (() => {
  let line = 0;
  return () => stdin[line++];
})();

const [N, M] = input().split(" ").map(Number);
const ans = [];
const ch = Array(N + 1).fill(0);

function dfs(n, arr) {
  // 종료 조건 및 정답 처리
  if (n === M) {
    ans.push(arr);
    return;
  }
  // 본 함수 호출
  for (let i = 1; i < N + 1; i++) {
    if (ch[i] === 0) {
      ch[i] = 1;
      dfs(n + 1, [...arr, i]);
      ch[i] = 0;
    }
  }
}
dfs(0, []);
ans.forEach((a) => console.log(a.join(" ")));

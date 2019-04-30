function remove(array, value) {
  let index = array.indexOf(value);

  if (index !== -1) {
    return array.splice(index, 1);
  }
  return false;
}

const keyCodeStore = {
  up: 38,
  right: 39,
  dawn: 40,
  left: 37
};

const game_over = {
  process: -1,
  lose: 0,
  win: 1
};

const keyCodeToDirection = {
  "38": "up",
  "39": "right",
  "40": "dawn",
  "37": "left"
};

const nothing = "nothing";
const wall = "wall";
const pers = "pers";
const apple = "apple";
const evill = "evill";

const type_of_cell = {
  "0": "nothing",
  "1": "wall",
  "10": "pers",
  "15": "apple",
  "20": "evill"
};

const move = {
  up: 38,
  right: 39,
  dawn: 40,
  left: 37,
  stop: -1
};

class Engine {
  constructor(canvas) {
    if (canvas === undefined) {
      throw TypeError();
    }

    this.canvas = canvas;
    this.context = this.canvas.getContext("2d");
    this.width = canvas.width;
    this.height = canvas.height;

    this.map = null;

    this.n_cell_x = null;
    this.n_cell_y = null;

    this.size = null;

    this.pers = null;

    this.speed = null;

    this.apples = null;

    this.evills = null;

    this.timer_id = null;

    this.score_inner = null;

    this.white_spaces = null;

    this.score = 0;

    this.a_star = null;

    this.game_over = game_over.process;
  }

  set_map(map) {
    if (
      map === undefined ||
      typeof map !== "object" ||
      map.length === undefined
    ) {
      throw TypeError();
    }

    this.n_cell_x = map[0].length;
    this.n_cell_y = map.length;

    this.size = this.width / Math.min(this.n_cell_x, this.n_cell_y);

    this.map = [];

    for (let row in map) {
      let new_row = [];

      for (let col in map[row]) {
        new_row.push(new Cell(col, row, map[row][col]));

        if (map[row][col] === 0) {
          this.white_spaces += 1;
        }
      }

      this.map.push(new_row);
    }
  }

  set_pers() {
    if (this.map === null) {
      throw Error("map is null");
    }

    for (let row in this.map) {
      for (let col in this.map[row]) {
        if (this.map[row][col].type === nothing) {
          this.pers = new Pers(col, row);

          this.map[row][col] = this.pers;

          return;
        }
      }
    }
  }

  set_evills(number) {
    if (this.map === null) {
      throw Error("map is null");
    }

    if (this.evills == null) {
      this.evills = [];
    }

    for (let evill = 0; evill < number; ++evill) {
      let x = null;
      let y = null;

      do {
        x = Math.round(Math.random() * (this.n_cell_x - 1));
        y = Math.round(Math.random() * (this.n_cell_y - 1));
      } while (
        this.map[y][x].type !== nothing &&
        this.map[y][x].type !== apple
      );

      this.evills.push(new Evill(x, y));
    }
  }

  set_apples(number) {
    if (this.map === null) {
      throw Error("map is null");
    }

    if (this.apples == null) {
      this.apples = [];
    }

    if (this.apples.length + number >= this.white_spaces) {
      try {
        throw Error("apples is overflow");
      } catch (error) {
        return;
      }
    }

    for (let apple = 0; apple < number; ++apple) {
      let x = null;
      let y = null;

      do {
        x = Math.round(Math.random() * (this.n_cell_x - 1));
        y = Math.round(Math.random() * (this.n_cell_y - 1));
      } while (this.map[y][x].type !== nothing);

      this.apples.push(new Apple(x, y));

      this.map[y][x] = this.apples[this.apples.length - 1];
    }
  }

  set_full_apples() {
    this.set_apples(this.white_spaces - 1);
  }

  draw() {
    for (let row in this.map) {
      for (let col in this.map[row]) {
        this.map[row][col].draw(this.context, this.size);
      }
    }

    for (let bot in this.evills) {
      this.evills[bot].draw(this.context, this.size);
    }
  }

  play(speed) {
    this.speed = speed;

    this.draw();
    document.addEventListener("keydown", this.key_dawn_handler);
    this.timer_id = setInterval(this.game, speed);
  }

  frame = 0;

  game = () => {
    this.move_pers();

    this.check_game_over();

    if (this.frame % 2 == 0) this.bot_mind();

    this.check_game_over();

    this.draw();

    if (this.score_inner !== null) {
      this.set_score(this.score_inner);
    }

    ++this.frame;

    if (this.frame >= 100) {
      this.frame = 0;
    }
  };

  check_game_over() {
    if (this.apples.length == 0) {
      this.close();

      console.log("YOU WIN!!!");

      this.game_over = game_over.win;

      this.set_apples(this.score);

      // this.score = 0;
    }

    for (let bot in this.evills) {
      if (
        this.pers.x === this.evills[bot].x &&
        this.pers.y === this.evills[bot].y
      ) {
        this.close();

        this.game_over = game_over.lose;

        console.log("GAME OVER!!!");

        this.set_apples(this.score);

        // this.score = 0;

        break;
      }
    }
  }

  key_dawn_handler = event => {
    let cash = this.pers.old_direction;

    this.pers.old_direction = this.pers.direction;

    if (event.keyCode == 32) {
      if (this.timer_id == null) {
        this.play(this.speed);
      } else {
        this.close();
      }
    }

    this.pers.moveTo(event.keyCode);

    if (this.pers.old_direction == this.pers.direction) {
      this.pers.old_direction = cash;
    }
  };

  bot_mind() {
    for (let bot in this.evills) {
      this.a_star = new A_star(this.map, this.evills);

      const path = this.a_star.search(this.evills[bot], this.pers);

      if (path.length > 0) {
        if (path[0].x - this.evills[bot].x == 1) {
          this.evills[bot].move_right();
        } else if (path[0].x - this.evills[bot].x == -1) {
          this.evills[bot].move_left();
        } else if (path[0].y - this.evills[bot].y == 1) {
          this.evills[bot].move_dawn();
        } else {
          this.evills[bot].move_up();
        }
      }

      this.bot_move(this.evills[bot]);
    }
  }

  bot_move(bot) {
    bot.move();

    let bot_x = bot.x;
    let bot_y = bot.y;

    if (this.map[bot_y][bot_x].type === wall) {
      bot.back();
      bot.stop();
    }
  }

  move_pers() {
    let old_pers_x = this.pers.x;
    let old_pers_y = this.pers.y;

    this.map[old_pers_y][old_pers_x] = new Cell(
      old_pers_x,
      old_pers_y,
      nothing
    );

    this.pers.move();

    let pers_x = this.pers.x;
    let pers_y = this.pers.y;

    if (
      this.map[pers_y][pers_x].type === nothing ||
      this.map[pers_y][pers_x].type === pers
    ) {
      this.map[pers_y][pers_x] = this.pers;
    } else if (this.map[pers_y][pers_x].type === wall) {
      this.pers.back();
      this.pers.stop();

      this.map[old_pers_y][old_pers_x] = this.pers;
    } else if (this.map[pers_y][pers_x].type === apple) {
      remove(this.apples, this.map[pers_y][pers_x]);

      this.map[pers_y][pers_x] = this.pers;

      this.score += 1;
    }
  }

  close() {
    if (this.timer_id !== null && typeof this.timer_id == "number") {
      clearInterval(this.timer_id);
      this.timer_id = null;
    }
  }

  set_score(score_inner) {
    if (typeof score_inner !== "object") {
      throw TypeError();
    }

    if (this.score_inner === null) {
      this.score_inner = score_inner;
    }

    if (this.game_over == game_over.process) {
      this.score_inner.innerHTML = `
      Score: <span>${this.score}</span>
    `;
    } else if (this.game_over == game_over.lose) {
      this.score_inner.innerHTML =
        "GAME OVER!!!<br/>" + `score <span>${this.score}</span>`;

      this.score = 0;
      this.game_over = game_over.process;
    } else {
      this.score_inner.innerHTML =
        "YOU WIN!!!<br/>" + `score <span>${this.score}</span>`;

      this.score = 0;
      this.game_over = game_over.process;
    }

    this.score_inner.style.color = "white";
    this.score_inner.style.textTransform = "uppercase";
    this.score_inner.style.fontFamily = "sans-serif";
    this.score_inner.style.textAlign = "center";
  }
}

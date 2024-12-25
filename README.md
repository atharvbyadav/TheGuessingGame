# 🎲 The Guessing Game

Welcome to **The Guessing Game**, a fun and simple terminal-based game where you test your luck by guessing a random number between 1 and 10. Place your bets, make your guess, and see if you can turn your luck into credit or lose it all in the thrill of the game!

---

## 🚀 Features

- **Personalized Experience**:
  - Enter your name at the start of the game for a customized gameplay experience.
  - Start with a customizable balance to play the game.

- **Dynamic Betting**:
  - Place a bet based on your available balance for each round.
  - Win **10x your bet** if you guess the correct number.

- **Randomized Outcomes**:
  - Every round features a random dice roll between 1 and 10, generated using `rand()` for unbiased results.

- **Error-Free Input Validation**:
  - The game ensures valid inputs for both bet amounts and guesses.
  - If the player tries to enter an invalid bet (e.g., more than the available balance or less than 1), the game will prompt them until they make a valid choice.
  - For guesses, it validates that the player picks a number between 1 and 10.

- **Real-Time Feedback**:
  - Immediate feedback on your performance after every round, including win/loss and the updated balance.
  - Special messages when you win a substantial amount, making the game more engaging.

- **Cross-Platform Compatibility**:
  - Works on both Windows (using `system("cls")` to clear the screen) and Linux/Mac (using `system("clear")` for clearing the console).

- **Prebuilt `.exe` File**:
  - A compiled `.exe` executable will be provided for those who want to play the game without needing a C compiler or other prerequisites.
  - Note: The `.exe` file is functional but may not be perfect. It’s a quick solution for those who want to experience the gameplay without compiling the code themselves.

---

## 🕹️ How to Play

1. **Start the Game**:
   - Run the program or execute the provided `.exe` file.
   - Enter your name to personalize the gameplay.

2. **Set Your Starting Balance**:
   - The game will prompt you to enter a starting balance, which must be greater than 0 to begin playing.

3. **Place Your Bet**:
   - Choose how much you want to wager for the round, keeping in mind that it cannot exceed your current balance.

4. **Make Your Guess**:
   - Guess a number between 1 and 10.

5. **Check the Result**:
   - If your guess matches the randomly generated number, you win **10x your bet**!
   - If your guess is incorrect, you lose your bet amount.

6. **Continue or Quit**:
   - Keep playing as long as you have credits remaining.
   - You can quit anytime by choosing ‘n’ when prompted.

---

## 🛠️ Code Highlights

1. **Random Number Generation**:
   - The game uses the `rand()` function, seeded with `time(0)` to generate random dice numbers between 1 and 10, ensuring fairness in every round.

2. **Input Validation**:
   - The `getValidAmount()` function ensures players only place valid bets, preventing accidental input errors (such as betting more than your available balance).
   - The `getValidGuess()` function ensures players only guess numbers within the allowed range (1-10).

3. **Modular and User-Friendly Design**:
   - Functions like `displayRules()`, `getValidAmount()`, and `getValidGuess()` help make the game flow smooth and easy to follow.
   - The game logic is modular and readable, making it easier to maintain and update.

4. **Interactive Gameplay**:
   - The game dynamically updates your balance after each round and provides clear messages based on whether you win or lose.
   - The game also congratulates you when you hit significant milestones like having a balance greater than 1000 credits.

5. **Cross-Platform Console Clearing**:
   - The game uses `system("cls")` to clear the console for Windows users. For Linux and Mac game uses `system("clear")` instead of `system("cls")` for compatibility.

6. **Prebuilt `.exe` File**:
   - A prebuilt `.exe` executable will be provided for Windows users who don’t want to compile the code themselves. This is a convenient option for quickly testing out the game.

---

## 📂 File Structure

- `TheGuessingGame.c`: The main source code for the game.
- `TheGuessingGame.exe`: The compiled executable version for Windows users.

---

## 🔮 Future Improvements

Here are some potential enhancements for future updates:
- **Difficulty Levels**: Introduce difficulty settings where the number range could be expanded (e.g., 1–20 or 1–50).
- **Leaderboard**: Add a leaderboard to track the highest scores and balances.
- **Player Progress Saving**: Allow players to save and load their game progress.
- **Graphical User Interface (GUI)**: Transition from a terminal-based game to a GUI-based one for a more immersive experience.

---

## ⚠️ Important Notes

- The `.exe` file provided is functional but may not be 100% perfect. It serves as a quick solution for those who wish to test the game without needing to compile the source code.
- If you're using Linux or Mac, the game can be compiled using any standard C compiler like `gcc`.

---

## 🤝 Contributing

Contributions are always welcome! If you have suggestions for improving the game or want to contribute to the project, feel free to fork the repository, make changes, and submit a pull request.

---

## 📝 Feedback

Enjoying the game or found a bug? Please reach out. Your feedback will help improve the game and make it even better for everyone!

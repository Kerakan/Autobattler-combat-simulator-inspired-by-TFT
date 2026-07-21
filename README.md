# Autobattler-combat-simulator-inspired-by-TFT
A TFT-inspired autobattler combat simulator built in C++ with Raylib.

This project features a hex grid system, combat optimized with spatial hashing, specific abilities for each champion, custom data architecture, per-star stats and a trait sinergy system. It is built as a portfolio project aiming towards AAA game studio roles.

Current Status, Final Step: Polishing, project is pretty much done and can see a fully functional combat using console inputs to select champions, might think about adding a team selection screen, combat and traits is fully done, have succeeded in solving primitive combat rounds, death handling complete, enemy targeting complete, hex grid initialization complete, trait application complete for the most part, champion pool definitions complete(17/17 Champion, balance will be done as part of the polish), trait enumeration complete, stats system complete, team creation complete.

I have tried to implement a data-driven approach but it has resulted in a lot of errors, a bunch of lost time and an overall decrease in FPS from 120 to 30, I am fairly sure it has something to do with the way I manage the data but I am unsure of where the error is, if anyone could help with it I have posted the files in the "main-data-driven" branch.

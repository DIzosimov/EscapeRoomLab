# EscapeRoomLab

## Summary

EscapeRoomLab is an Unreal Engine 5 C++ project for practising gameplay fundamentals with clean actor and component design. The gameplay classes are a pickup base class (`PickupBase.h`), a key ring (`KeyRing.h`), light switches (`LightSwitch.h`) and doors (`Door.h`), which are the building blocks of an escape room. The door-opening mechanism is not yet verified from the code (see Assumptions in projects-update.md). The project also carries the Unreal third-person template's character, game mode and player controller, plus its `Variant_Combat`, `Variant_Platforming` and `Variant_SideScrolling` folders.

## Role

Creator and developer.

## Tech

- Unreal Engine 5
- C++ (modules under `EscapeRoomLab/Source/EscapeRoomLab`, with `Public` and `Private` folders)
- Door mechanism not yet verified (class is `Door.h`; whether it uses Timelines wasn't confirmed from the code)

## Setup / Run

1. Install Unreal Engine 5 through the Epic Games Launcher (free) and, on Windows, Visual Studio with the "Game development with C++" workload.
2. Clone the repository.
3. Right-click `EscapeRoomLab/EscapeRoomLab.uproject` and choose **Generate Visual Studio project files**.
4. Open the generated solution, build the `EscapeRoomLabEditor` target (defined in `EscapeRoomLab/Source/EscapeRoomLabEditor.Target.cs`) and run it, or double-click the `.uproject` to open the editor.

## Status

A small personal lab, still early (3 commits at the time of writing). It is a practice project, not a shipped game.

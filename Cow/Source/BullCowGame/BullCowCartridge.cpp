// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
    PrintLine(TEXT("Welcome to the game you have to guess the word..."));
    PrintLine(FString::Printf(TEXT("It has %i letters"),HiddenWord.Len()));
    PrintLine(FString::Printf(TEXT("You have %i lifes"),Lifes));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    CheckInput(Input);
}

void UBullCowCartridge::CheckInput(const FString Word){
    if(!IsIsogram(Word)){
        PrintLine(TEXT("The word is Isogram with the code"));
    }
    if(Word.Len() != HiddenWord.Len()){
        PrintLine(TEXT("The word you supplied does not have the same length"));
        --Lifes;
        PrintLine(FString::Printf(TEXT("You still have %i lives"),Lifes));
        GameOVer = true;
    }
    else if(Word != HiddenWord){
        PrintLine(TEXT("The word you supplied is diferent from the code"));
        --Lifes;
        PrintLine(FString::Printf(TEXT("You still have %i lives"),Lifes));
        GameOVer = true;
    }
    else{
        PrintLine(TEXT("You win GAAA :v"));
        ++Lifes;
        PrintLine(FString::Printf(TEXT("You now have %i lives"),Lifes));
    }
    if(GameOVer){
        if(Lifes == 0){
            PrintLine(TEXT("She is gone :'v. \n You lose her heath :v"));
        }else{
            PrintLine(TEXT("Press any key to continue..."));
            //ClearScreen();
            GameOVer = false;
        }
    }
}

bool UBullCowCartridge::IsIsogram(FString Word) const{
    /*for (int i = 0; i < Word.Len(); i++)
    {
        if (Word.Contains(&Word[i]))
            return true;
    }
    return false;*/
    return false;
    
}

void UBullCowCartridge::SetupGame(){
    HiddenWord = "ELLA";
    GameOVer = false;
    Lifes = 5;
}
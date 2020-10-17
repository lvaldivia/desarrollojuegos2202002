// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm Component"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera->SetupAttachment(SpringArm);
}


void ATank::CalculateMoveInput(float Value){
    
    MoveDirection = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds,0,0);
}
void ATank::CalculateRotateInput(float Value){
    float RotateAmount = Value * RotateSpeed * GetWorld()->DeltaTimeSeconds;
    FRotator Rotation = FRotator(0,RotateAmount,0);
    RotationDirection = FQuat(Rotation);
}
void ATank::Move(){
    AddActorLocalOffset(MoveDirection,true);
}
void ATank::Rotate(){
    AddActorLocalRotation(RotationDirection,true);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
    PlayerController = Cast<APlayerController>(GetController());
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    Rotate();
    Move();
    if(PlayerController){
        FHitResult TraceHitResult;
        PlayerController->GetHitResultUnderCursor(ECC_Visibility,false,TraceHitResult);
        FVector FHitLocation = TraceHitResult.ImpactPoint;
        RotateTurret(FHitLocation);
    }
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward",this,&ATank::CalculateMoveInput);
    PlayerInputComponent->BindAxis("Turn",this,&ATank::CalculateRotateInput);
}

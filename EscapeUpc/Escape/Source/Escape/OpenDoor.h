// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

private:
	UPROPERTY(EditAnywhere)
	float TargetYaw = 90.0f;
	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* Pressure; 

	UPROPERTY(EditAnywhere)
	AActor* ActorOpen; 
	float DoorLastOpened;
	float DoorCloseDelay = 2.f;

	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	void SetActor();
	void InitialValues();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

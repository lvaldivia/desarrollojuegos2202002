// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

class ATankModeBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOONTANKS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
	void TakeDamage(AActor* DamageActor, float Damage,const UDamageType* DamageType,
			AController* InstigatedBody, AActor* DamageCauser);
private:
	UPROPERTY(EditAnywhere)
	float DefaultHealth  = 100.0f;
	float Health = 0.0;
	ATankModeBase* GameModeRef;
	
};

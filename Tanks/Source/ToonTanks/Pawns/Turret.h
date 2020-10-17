// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"

#include "Turret.generated.h"


/**
 * 
 */
UCLASS()
class TOONTANKS_API ATurret : public ABasePawn
{
	GENERATED_BODY()
	private:
		UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combat",meta=(AllowPrivateAccess="true"))
		float FireRate = 2.0f;
		UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combat",meta=(AllowPrivateAccess="true"))
		float FireRange = 500.0f;
		void CheckFireCondition();
		FTimerHandle FireRateTimeHandle;
		ATank* Player;
		float ReturnDistanceToPlayer();
	protected:
		virtual void BeginPlay()override;
		virtual void HandleDestruction() override;
	public:
		virtual void Tick(float DeltaTime) override;
};

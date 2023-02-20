// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ShooterGameMode.generated.h"

/** Add a new custom match state in the GameMode */
namespace MatchState
{
	extern const FName Cooldown;
}

/**
 * 
 */
UCLASS()
class MULTIPLAYERSHOOTER_API AShooterGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AShooterGameMode();
	virtual void PlayerEliminated(class AMainCharacter* EliminatedCharacter, class AShooterPlayerController* VictimController, class AShooterPlayerController* AttackerController);
	virtual void RequestRespawn(class AMainCharacter* EliminatedCharacter, class AController* EliminatedController);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnMatchStateSet() override;
	
private:
	/** The time cost for entering the map */
	float LevelStartingTime = 0.f;
	
	/** Warmup time before starting the game */
	UPROPERTY(EditDefaultsOnly, Category = Match)
	float WarmupTime = 10.f;

	/** Match time when MatchState is InProgress */
	UPROPERTY(EditDefaultsOnly, Category = Match)
	float MatchTime = 10.f;

	/** Cooldown time when MatchState is InProgress and the match countdown has finished */
	UPROPERTY(EditDefaultsOnly, Category = Match)
	float CooldownTime = 10.f;

	/** Countdown time since the players have entered the map */
	float CountdownTime = 10.f;

public:
	FORCEINLINE float GetLevelStartingTime() const { return LevelStartingTime; }
	FORCEINLINE float GetWarmupTime() const { return WarmupTime; }
	FORCEINLINE float GetMatchTime() const { return MatchTime; }
	FORCEINLINE float GetCooldownTime() const { return CooldownTime; }
};

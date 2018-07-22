// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSExtractZone.generated.h"

class UBoxComponent;
class UDecalComponent;
class USoundBase;


UCLASS()
class FPSGAME_API AFPSExtractZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSExtractZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent * OverlapComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UDecalComponent * DecalComp;

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	USoundBase *ObjectiveMissingSound;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
};

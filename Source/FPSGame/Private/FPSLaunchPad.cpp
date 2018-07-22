// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSLaunchPad.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AFPSLaunchPad::AFPSLaunchPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetBoxExtent(FVector(75, 75, 50));
	RootComponent = OverlapComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	LaunchStrength = 1500;
	LaunchPitchAngle = 45.0f;

}

// Called when the game starts or when spawned
void AFPSLaunchPad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSLaunchPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSLaunchPad::NotifyActorBeginOverlap(AActor * OtherActor)
{
	FRotator LaunchDirection = GetActorRotation();
	LaunchDirection.Pitch = LaunchPitchAngle;
	FVector LaunchVelocity = LaunchDirection.Vector() * LaunchStrength;
	
	ACharacter *OtherCharacter = Cast<ACharacter>(OtherActor);
	if (OtherCharacter) {
		OtherCharacter->LaunchCharacter(LaunchVelocity, true, true);

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ActivateLaunchPadEffect, GetActorLocation());




	}


}


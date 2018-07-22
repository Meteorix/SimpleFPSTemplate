// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSExtractZone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "FPSCharacter.h"
#include "FPSGameMode.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AFPSExtractZone::AFPSExtractZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetBoxExtent(FVector(200.0f));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	OverlapComp->SetHiddenInGame(false);
	RootComponent = OverlapComp;

	
	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->DecalSize = FVector(200.0f, 200.0f, 200.0f);
	DecalComp->SetupAttachment(OverlapComp);

}

// Called when the game starts or when spawned
void AFPSExtractZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSExtractZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSExtractZone::NotifyActorBeginOverlap(AActor * OtherActor)
{

	AFPSCharacter *MyPawn = Cast<AFPSCharacter>(OtherActor);
	
	if (MyPawn == nullptr) {
		return;
	}
	if (MyPawn->bIsCarryingObjective)
	{
		AFPSGameMode* GM = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());
		if (GM) {
			GM->CompleteMission(MyPawn);
		}
	}
	else {
		UGameplayStatics::PlaySound2D(this, ObjectiveMissingSound);
	}
	UE_LOG(LogTemp, Log, TEXT("got extract overlapped"));
}


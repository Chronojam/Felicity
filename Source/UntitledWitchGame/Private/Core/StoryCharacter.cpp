// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/StoryCharacter.h"
#include "Core/StoryPlayerState.h"
#include "Placeables/Pickups/Pickup.h"
#include "Core/Interactables/Openable.h"
#include "Weapons/ThrowablePotion.h"
#include "Weapons/Weapon.h"
#include "Character/PlayerAnimInstance.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"

// Sets default values
AStoryCharacter::AStoryCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AStoryCharacter::BeginOverlap);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}


// Called when the game starts or when spawned
void AStoryCharacter::BeginPlay()
{
	Super::BeginPlay();
	IsUsingAbility = false;
}

// Called every frame
void AStoryCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AStoryCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("UseAbility", IE_Pressed, this, &AStoryCharacter::UseAbility);

	PlayerInputComponent->BindAxis("MoveForward", this, &AStoryCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AStoryCharacter::MoveRight);
	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AStoryCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AStoryCharacter::LookUpAtRate);

	PlayerInputComponent->BindAxis("CameraZoom", this, &AStoryCharacter::CameraZoom);
}

void AStoryCharacter::ThrowRandomPotion() {
	/*auto index = UKismetMathLibrary::RandomIntegerInRange(0, Ability_RandomPotionBPS.Num() - 1);
	auto bp = Ability_RandomPotionBPS[index];

	auto animInst = Cast<UFelicityAnimInstance>(this->GetMesh()->GetAnimInstance());
	animInst->PlayThrow();

	auto potion = GetWorld()->SpawnActor<AThrowablePotion>(bp, GetActorLocation() + GetActorForwardVector() * 50, GetActorRotation());
	potion->AttachToComponent(this->GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true), TEXT("RightHandSocket"));

	FTimerHandle TimerHandle;
	FTimerDelegate TimerDel;

	TimerDel.BindUFunction(this, FName("ThrowFromHand"), potion);
	GetWorldTimerManager().SetTimer(TimerHandle, TimerDel, 1.0f, false);
	*/

}
void AStoryCharacter::ThrowFromHand(AThrowablePotion* potion) {
	// After a second, we want the potion to detach from the hand,
	// enable physics and then add some force.
	/*potion->DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, false));

	TArray<UStaticMeshComponent*> StaticComps;
	potion->GetComponents<UStaticMeshComponent>(StaticComps);
	for (auto x : StaticComps) {
		x->SetSimulatePhysics(true);
	}

    auto potionPrim = Cast<UPrimitiveComponent>(potion->GetRootComponent());
	auto manager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);

	// Launch it in the direction we re looking at.
	// add our own speed onto it.
	//FVector::Size()
	auto Speed = GetMovementComponent()->Velocity.Size();
	potionPrim->AddForce(FVector(0, 0, 5000) + manager->GetActorForwardVector() * 125000 + (3 * Speed), NAME_None, true);
	IsUsingAbility = false;
	*/
}


void AStoryCharacter::UseAbility() {
	if (IsUsingAbility) return;
	auto State = Cast<AStoryPlayerState>(this->GetPlayerState());
	if (State == nullptr) return;
	if (State->CurrentAbility == nullptr) return;

	auto animInst = Cast<UPlayerAnimInstance>(this->GetMesh()->GetAnimInstance());

	// Use the primary Ability
	State->CurrentAbility->Primary(animInst);
	//ThrowRandomPotion();
	//auto hacky = Cast<UPrimitiveComponent>(potion->GetRootComponent());

	//auto manager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	//auto LookAt = manager->GetActorForwardVector() * 100;

	//hacky->AddForce(FVector(0, 0, 5000) + manager->GetActorForwardVector() * 125000, NAME_None, true);
}

void AStoryCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}
void AStoryCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AStoryCharacter::MoveForward(float Value)
{
	if ((Controller != NULL))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
		ForwardDirection = Value;
	}
}
void AStoryCharacter::MoveRight(float Value)
{
	if ((Controller != NULL))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
		RightDirection = Value;
	}
}
void AStoryCharacter::CameraZoom(float Value) {
	CameraBoom->TargetArmLength = CameraBoom->TargetArmLength += Value;
}

void AStoryCharacter::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	auto State = Cast<AStoryPlayerState>(this->GetPlayerState());
	if (State == nullptr) return;

	if (OtherActor->Implements<UPickup>()) {
		IPickup* PickedUpItem = Cast<IPickup>(OtherActor);
		if (PickedUpItem == nullptr) return;
		PickedUpItem->Pickup(State);
		GetWorld()->DestroyActor(OtherActor);
	}
	if (OtherActor->Implements<UOpenable>()) {
		IOpenable* Openable = Cast<IOpenable>(OtherActor);
		if (Openable == nullptr) return;
		Openable->Open(State);
	}
}
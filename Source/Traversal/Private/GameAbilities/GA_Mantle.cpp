// Fill out your copyright notice in the Description page of Project Settings.
#include "GameAbilities/GA_Mantle.h"
#include "AbilitySystemComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"


void UGA_Mantle::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) {
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!CommitAbility(Handle, ActorInfo, ActivationInfo)) {
		UE_LOG(LogTemp, Warning, TEXT("[UGA_Mantle] Error Commit"));
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	Character = Cast<ATraversalCharacter>(ActorInfo->AvatarActor.Get());
	if (!Character || !MantlHeight || !MantleLow)
	{
		UE_LOG(LogTemp, Warning, TEXT("[UGA_Mantle] Error Cast"));
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	UAnimMontage* MontagePlay = MantlHeight;
	const float Height = Character->Height;
	const float SeparatorHeight = Character->MaxHeightVaulting;

	if (Height >= SeparatorHeight) {
		MontagePlay = MantlHeight;
	}
	if (Height < SeparatorHeight) {
		MontagePlay = MantleLow;
	}
	Character->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	UAbilityTask_PlayMontageAndWait* AnimTask = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, NAME_None, MontagePlay, 1.0f, NAME_None, true, 1.0f, 0.0f);
	
	AnimTask->OnCompleted.AddDynamic(this, &UGA_Mantle::OnAnimCompleted);
	AnimTask->OnInterrupted.AddDynamic(this, &UGA_Mantle::OnAnimInterrupted);
	AnimTask->OnCancelled.AddDynamic(this, &UGA_Mantle::OnAnimInterrupted);
	UE_LOG(LogTemp, Warning, TEXT("[UGA_Mantle] Test Activation"));

	AnimTask->ReadyForActivation();

}

void UGA_Mantle::OnAnimCompleted()
{
	if (Character) {
		Character->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UGA_Mantle::OnAnimInterrupted()
{
	if (Character) {
		Character->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}
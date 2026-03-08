namespace MWChassis {
	SuspensionRacer* GetSuspensionRacer(uintptr_t ptr) {
		ptr -= offsetof(SuspensionRacer, tmpChassis);
		return (SuspensionRacer*)ptr;
	}

	const char* __thiscall GetChassisName(uintptr_t ptr) { return "ChassisHuman"; }
	float __thiscall GetWheelTraction(uintptr_t ptr, unsigned int index) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mTires[index]->GetTraction();
	}
	float __thiscall GetWheelDynamicSlipAngle(uintptr_t ptr, unsigned int index) { // todo this is different
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mTires[index]->GetSlipAngle();
	}
	float __thiscall GetWheelSlipRatio(uintptr_t ptr, unsigned int index) { // todo this is different
		auto pThis = GetSuspensionRacer(ptr);
		return 1.0;
		//return pThis->mTires[index]->GetSlipAngle();
	}
	float __thiscall GetDragBoost(uintptr_t ptr) { return 0.0; }
	unsigned int __thiscall GetNumWheels(uintptr_t ptr) { return 4; }
	const UMath::Vector3 *__thiscall GetWheelPos(uintptr_t ptr, unsigned int i) {
		auto pThis = GetSuspensionRacer(ptr);
		return &pThis->mTires[i]->mPosition;
	}
	const UMath::Vector3 *__thiscall GetWheelLocalPos(uintptr_t ptr, unsigned int i) {
		auto pThis = GetSuspensionRacer(ptr);
		return &pThis->mTires[i]->mLocalArm;
	}
	const UMath::Vector3 *__thiscall GetWheelCenterPos(uintptr_t ptr, UMath::Vector3 *result, unsigned int i) {
		auto pThis = GetSuspensionRacer(ptr);
		*result = pThis->mTires[i]->GetPosition();
		if (!pThis->mRB) {
			return result;
		} else {
			UMath::ScaleAdd(*pThis->mRB->GetUpVector(), pThis->mTires[i]->GetRadius(), *result, *result);
			return result;
		}
	}
	float __thiscall GetWheelTorque(uintptr_t ptr, unsigned int i) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mTires[i]->GetTotalTorque();
	}
	float __thiscall GetWheelBrakeTorque(uintptr_t ptr, unsigned int i) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mTires[i]->mBrakeTorque;
	}
	float __thiscall GetWheelLoad(uintptr_t ptr, unsigned int i) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mTires[i]->GetLoad();
	}
	float __thiscall GetWheelRoadHeight(uintptr_t ptr, unsigned int i) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mTires[i]->GetNormal().w;
	}
	bool __thiscall IsWheelOnGround(uintptr_t ptr, unsigned int i) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mTires[i]->IsOnGround();
	}
	float __thiscall GetCompression(uintptr_t ptr, unsigned int i) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mTires[i]->GetCompression();
	}
	float __thiscall GuessCompression(uintptr_t ptr, unsigned int id, float downforce) {
		auto pThis = GetSuspensionRacer(ptr);
		float compression = 0.0f;
		if (downforce < 0.0f) {
			unsigned int axle = id / 2;
			float spring_weight = LBIN2NM(pThis->mCarInfo.GetLayout()->SPRING_STIFFNESS.At(axle));
			downforce *= 0.25f;
			compression = -downforce / spring_weight;
		}
		return compression;
	}
	void __thiscall ForceCompression(uintptr_t ptr, unsigned int id, float f) { // todo does this break stuff due to uc using it
		auto pThis = GetSuspensionRacer(ptr);
		pThis->mTires[id]->SetCompression(f);
	}
	float __thiscall GetWheelSlip(uintptr_t ptr, unsigned int id) {
		auto pThis = GetSuspensionRacer(ptr);
		pThis->mTires[id]->GetCurrentSlip();
	}
	float __thiscall GetToleratedSlip(uintptr_t ptr, unsigned int id) {
		auto pThis = GetSuspensionRacer(ptr);
		pThis->mTires[id]->GetToleratedSlip();
	}
	float __thiscall GetWheelSkid(uintptr_t ptr, unsigned int id) {
		auto pThis = GetSuspensionRacer(ptr);
		pThis->mTires[id]->GetLateralSpeed();
	}
	float __thiscall GetWheelSlipAngle(uintptr_t ptr, unsigned int id) {
		auto pThis = GetSuspensionRacer(ptr);
		pThis->mTires[id]->GetSlipAngle();
	}
	const UMath::Vector3* __thiscall GetWheelRoadNormal(uintptr_t ptr, unsigned int id) {
		auto pThis = GetSuspensionRacer(ptr);
		return (UMath::Vector3*)&pThis->mTires[id]->mNormal;
	}
	const SimSurface* __thiscall GetWheelRoadSurface(uintptr_t ptr, unsigned int id) {
		auto pThis = GetSuspensionRacer(ptr);
		return &pThis->mTires[id]->mSurface;
	}
	const UMath::Vector3* __thiscall GetWheelVelocity(uintptr_t ptr, unsigned int id) {
		auto pThis = GetSuspensionRacer(ptr);
		return (UMath::Vector3*)&pThis->mTires[id]->mVelocity;
	}
	int __thiscall GetNumWheelsOnGround(uintptr_t ptr) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mNumWheelsOnGround;
	}
	int __thiscall GetNumWheelsOnBand(uintptr_t ptr) { // todo what is this?
		auto pThis = GetSuspensionRacer(ptr);
		//return pThis->mNumWheelsOnGround;
		return 0;
	}
	float __thiscall GetWheelAngularVelocity(uintptr_t ptr, int i) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mTires[i]->GetAngularVelocity();
	}
	void __thiscall SetWheelAngularVelocity(uintptr_t ptr, int i, float f) {
		auto pThis = GetSuspensionRacer(ptr);
		pThis->mTires[i]->SetAngularVelocity(f);
	}
	void __thiscall SetWheelMaxAngularVelocity(uintptr_t ptr, int i, float f) { // todo this doesn't exist
		auto pThis = GetSuspensionRacer(ptr);
	}
	float __thiscall GetWheelSteer(uintptr_t ptr, int wheel) {
		auto pThis = GetSuspensionRacer(ptr);
		return wheel < 2 ? RAD2ANGLE(pThis->mSteering.Wheels[wheel]) : 0.0f;
	}
	bool __thiscall CalculateFFBSteeringState(uintptr_t ptr, FFBSteeringState*) {
		auto pThis = GetSuspensionRacer(ptr);
		return false;
	}
	float __thiscall GetSuspensionDigression(uintptr_t ptr, int i) { // todo is this correct
		auto pThis = GetSuspensionRacer(ptr);
		return 1.0f - pThis->mCarInfo.GetLayout()->SHOCK_DIGRESSION.At(IsRear(i));
	}
	float __thiscall GetWheelLateralForce(uintptr_t ptr, int i) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mTires[i]->mLateralForce;
	}
	float __thiscall GetRideHeight(uintptr_t ptr, unsigned int idx) {
		auto pThis = GetSuspensionRacer(ptr);
		float ride = pThis->GetRideHeight(idx);
		//const Physics::Tunings *tunings = GetVehicle()->GetTunings();
		//if (tunings) {
		//	ride += INCH2METERS(tunings->Value[Physics::Tunings::RIDEHEIGHT]);
		//}
		return ride;
	}
	float __thiscall GetWheelRadius(uintptr_t ptr, unsigned int idx) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mTires[idx]->GetRadius();
	}
	float __thiscall GetMaxSteering(uintptr_t ptr) {
		auto pThis = GetSuspensionRacer(ptr);
		return DEG2ANGLE(pThis->mSteering.Maximum);
	}
	void __thiscall MatchSpeed(uintptr_t ptr, float speed) {
		auto pThis = GetSuspensionRacer(ptr);
		pThis->MatchSpeed(speed);
	}
	float __thiscall GetDriveshaftTorqueEffect(uintptr_t ptr) {
		auto pThis = GetSuspensionRacer(ptr);
		return 0.0;
	}
	float __thiscall GetRenderMotion(uintptr_t ptr) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mCarInfo.GetLayout()->RENDER_MOTION;
	}
	ISteeringWheel::SteeringType __thiscall GetSteeringType(uintptr_t ptr) {
		auto pThis = GetSuspensionRacer(ptr);

		ISteeringWheel::SteeringType steer_type = ISteeringWheel::kGamePad;

		IPlayer *player = pThis->GetOwner()->GetPlayer();
		if (player) {
			ISteeringWheel *device = player->GetSteeringDevice();

			if (device && device->IsConnected()) {
				steer_type = device->GetSteeringType();
			}
		}

		return steer_type;
	}
	float __thiscall GetWheelTorqueRatio(uintptr_t ptr, int i) { // todo what is this
		auto pThis = GetSuspensionRacer(ptr);
		return 1.0;
	}
	float __thiscall GetWheelIdealTorque(uintptr_t ptr, int i) { // todo what is this
		auto pThis = GetSuspensionRacer(ptr);
		return 1.0;
	}
	void __thiscall SetWheelRemoved(uintptr_t ptr, int i, bool b) { // todo
		auto pThis = GetSuspensionRacer(ptr);
	}
	void __thiscall SetWheelMaximumTorqueRatio(uintptr_t ptr, int i, float f) { // todo
		auto pThis = GetSuspensionRacer(ptr);
	}
	bool __thiscall IsAntiBrakeLockOn(uintptr_t ptr) { return false; }
	int __thiscall GetAntiBrakeLockLevel(uintptr_t ptr) { return 0; }
	void __thiscall SetAntiBrakeLockLevel(uintptr_t ptr, int i) { return; }
	bool __thiscall IsStabilityManagementOn(uintptr_t ptr) { return false; }
	int __thiscall GetStabilityManagementLevel(uintptr_t ptr) { return 0; }
	void __thiscall SetStabilityManagementLevel(uintptr_t ptr, int i) { return; }
	bool __thiscall IsDriftAsssistOn(uintptr_t ptr) { return false; }
	int __thiscall GetDriftAssistLevel(uintptr_t ptr) { return 0; }
	void __thiscall SetDriftAssistLevel(uintptr_t ptr, int i) { return; }
	bool __thiscall IsDriftGlueToRoadOn(uintptr_t ptr) { return false; }
	int __thiscall GetDriftGlueToRoadLevel(uintptr_t ptr) { return 0; }
	void __thiscall SetDriftGlueToRoadLevel(uintptr_t ptr, int i) { return; }
	bool __thiscall IsDriftDynamicBrakeOn(uintptr_t ptr) { return false; }
	int __thiscall GetDriftDynamicBrakeLevel(uintptr_t ptr) { return 0; }
	void __thiscall SetDriftDynamicBrakeLevel(uintptr_t ptr, int i) { return; }
	bool __thiscall IsDriftSpeedControlOn(uintptr_t ptr) { return false; }
	int __thiscall GetDriftSpeedControlLevel(uintptr_t ptr) { return 0; }
	void __thiscall SetDriftSpeedControlLevel(uintptr_t ptr, int i) { return; }
	bool __thiscall IsRacelineAssistOn(uintptr_t ptr) { return false; }
	int __thiscall GetRacelineAssistLevel(uintptr_t ptr) { return 0; }
	void __thiscall SetRacelineAssistLevel(uintptr_t ptr, int i) { return; }
	bool __thiscall IsBrakingAssistOn(uintptr_t ptr) { return false; }
	int __thiscall GetBrakingAssistLevel(uintptr_t ptr) { return 0; }
	void __thiscall SetBrakingAssistLevel(uintptr_t ptr, int i) { return; }
	float __thiscall GetDragCoefficient(uintptr_t ptr) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mCarInfo.GetLayout()->DRAG_COEFFICIENT;
	}
	float __thiscall GetDownCoefficient(uintptr_t ptr) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mCarInfo.GetLayout()->AERO_COEFFICIENT.GetValue(UNDERCOVER_AeroCoeffAtValue);
	}
	float __thiscall GetStaticGripForSpeed(uintptr_t ptr, float f) { // todo
		auto pThis = GetSuspensionRacer(ptr);
		return 0.8;
	}
	void __thiscall SetClutchKickExtraTireSpin(uintptr_t ptr, float f) { // todo
		auto pThis = GetSuspensionRacer(ptr);
	}
	float __thiscall GetWheelieAngle(uintptr_t ptr) { // todo
		auto pThis = GetSuspensionRacer(ptr);
		return 0.0;
	}
	bool __thiscall IsStaticResetCondition(uintptr_t ptr) {
		auto pThis = GetSuspensionRacer(ptr);
		return false;
	}
	void __thiscall SetAICatchOverride(uintptr_t ptr, bool) {
		auto pThis = GetSuspensionRacer(ptr);
	}
	float __thiscall GetSlipToGripImpactTime(uintptr_t ptr) { // todo
		auto pThis = GetSuspensionRacer(ptr);
		return 0.0;
	}
	float __thiscall GetJumpTime(uintptr_t ptr) {
		auto pThis = GetSuspensionRacer(ptr);
		return pThis->mJumpTime;
	}
	float __thiscall GetTimeFromLanding(uintptr_t ptr) { // todo
		auto pThis = GetSuspensionRacer(ptr);
		return 0.0;
	}
	bool __thiscall IsCounterSteering(uintptr_t ptr) { // todo
		auto pThis = GetSuspensionRacer(ptr);
		return false;
	}
}

void* NewChassisVTable[] = {
		(void*)0x7B8560, // generic interface dtor
		(void*)&MWChassis::GetChassisName,
		(void*)&MWChassis::GetWheelTraction,
		(void*)&MWChassis::GetWheelDynamicSlipAngle,
		(void*)&MWChassis::GetWheelSlipRatio,
		(void*)&MWChassis::GetDragBoost,
		(void*)&MWChassis::GetNumWheels,
		(void*)&MWChassis::GetWheelPos,
		(void*)&MWChassis::GetWheelLocalPos,
		(void*)&MWChassis::GetWheelCenterPos,
		(void*)&MWChassis::GetWheelTorque,
		(void*)&MWChassis::GetWheelBrakeTorque,
		(void*)&MWChassis::GetWheelLoad,
		(void*)&MWChassis::GetWheelRoadHeight,
		(void*)&MWChassis::IsWheelOnGround,
		(void*)&MWChassis::GetCompression,
		(void*)&MWChassis::GuessCompression,
		(void*)&MWChassis::ForceCompression,
		(void*)&MWChassis::GetWheelSlip,
		(void*)&MWChassis::GetToleratedSlip,
		(void*)&MWChassis::GetWheelSkid,
		(void*)&MWChassis::GetWheelSlipAngle,
		(void*)&MWChassis::GetWheelRoadNormal,
		(void*)&MWChassis::GetWheelRoadSurface,
		(void*)&MWChassis::GetWheelVelocity,
		(void*)&MWChassis::GetNumWheelsOnGround,
		(void*)&MWChassis::GetNumWheelsOnBand,
		(void*)&MWChassis::GetWheelAngularVelocity,
		(void*)&MWChassis::SetWheelAngularVelocity,
		(void*)&MWChassis::SetWheelMaxAngularVelocity,
		(void*)&MWChassis::GetWheelSteer,
		(void*)&MWChassis::CalculateFFBSteeringState,
		(void*)&MWChassis::GetSuspensionDigression,
		(void*)&MWChassis::GetWheelLateralForce,
		(void*)&MWChassis::GetRideHeight,
		(void*)&MWChassis::GetWheelRadius,
		(void*)&MWChassis::GetMaxSteering,
		(void*)&MWChassis::MatchSpeed,
		(void*)&MWChassis::GetDriveshaftTorqueEffect,
		(void*)&MWChassis::GetRenderMotion,
		(void*)&MWChassis::GetSteeringType,
		(void*)&MWChassis::GetWheelTorqueRatio,
		(void*)&MWChassis::GetWheelIdealTorque,
		(void*)&MWChassis::SetWheelRemoved,
		(void*)&MWChassis::SetWheelMaximumTorqueRatio,
		(void*)&MWChassis::IsAntiBrakeLockOn,
		(void*)&MWChassis::GetAntiBrakeLockLevel,
		(void*)&MWChassis::SetAntiBrakeLockLevel,
		(void*)&MWChassis::IsStabilityManagementOn,
		(void*)&MWChassis::GetStabilityManagementLevel,
		(void*)&MWChassis::SetStabilityManagementLevel,
		(void*)&MWChassis::IsDriftAsssistOn,
		(void*)&MWChassis::GetDriftAssistLevel,
		(void*)&MWChassis::SetDriftAssistLevel,
		(void*)&MWChassis::IsDriftGlueToRoadOn,
		(void*)&MWChassis::GetDriftGlueToRoadLevel,
		(void*)&MWChassis::SetDriftGlueToRoadLevel,
		(void*)&MWChassis::IsDriftDynamicBrakeOn,
		(void*)&MWChassis::GetDriftDynamicBrakeLevel,
		(void*)&MWChassis::SetDriftDynamicBrakeLevel,
		(void*)&MWChassis::IsDriftSpeedControlOn,
		(void*)&MWChassis::GetDriftSpeedControlLevel,
		(void*)&MWChassis::SetDriftSpeedControlLevel,
		(void*)&MWChassis::IsRacelineAssistOn,
		(void*)&MWChassis::GetRacelineAssistLevel,
		(void*)&MWChassis::SetRacelineAssistLevel,
		(void*)&MWChassis::IsBrakingAssistOn,
		(void*)&MWChassis::GetBrakingAssistLevel,
		(void*)&MWChassis::SetBrakingAssistLevel,
		(void*)&MWChassis::GetDragCoefficient,
		(void*)&MWChassis::GetDownCoefficient,
		(void*)&MWChassis::GetStaticGripForSpeed,
		(void*)&MWChassis::SetClutchKickExtraTireSpin,
		(void*)&MWChassis::GetWheelieAngle,
		(void*)&MWChassis::IsStaticResetCondition,
		(void*)&MWChassis::SetAICatchOverride,
		(void*)&MWChassis::GetSlipToGripImpactTime,
		(void*)&MWChassis::GetJumpTime,
		(void*)&MWChassis::GetTimeFromLanding,
		(void*)&MWChassis::IsCounterSteering,
};
adb shell am force-stop com.beatgames.beatsaber
adb shell am start com.beatgames.beatsaber/com.unity3d.player.UnityPlayerActivity
Start-Sleep 1
adb shell am start com.beatgames.beatsaber/com.unity3d.player.UnityPlayerActivity | Out-Null
$str = &adb shell dumpsys power | Select-String "mHoldingDisplaySuspendBlocker"
$on = $str.ToString().Contains("true")
if (-not $on) {
    adb shell input keyevent KEYCODE_POWER
}

package in.glivade.voicecontrol;

import android.content.ComponentName;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

import com.afollestad.materialdialogs.MaterialDialog.Builder;
import com.afollestad.materialdialogs.Theme;

public class MainActivity extends AppCompatActivity {

    private static final Intent[] AUTO_START_INTENTS = {
            new Intent().setComponent(new ComponentName("com.samsung.android.lool",
                    "com.samsung.android.sm.ui.battery.BatteryActivity")),
            new Intent("miui.intent.action.OP_AUTO_START").addCategory(Intent.CATEGORY_DEFAULT),
            new Intent().setComponent(new ComponentName("com.miui.securitycenter",
                    "com.miui.permcenter.autostart.AutoStartManagementActivity")), new Intent().setComponent(
            new ComponentName("com.letv.android.letvsafe",
                    "com.letv.android.letvsafe.AutobootManageActivity")), new Intent().setComponent(
            new ComponentName("com.huawei.systemmanager",
                    "com.huawei.systemmanager.optimize.process.ProtectActivity")), new Intent().setComponent(
            new ComponentName("com.coloros.safecenter",
                    "com.coloros.safecenter.permission.startup.StartupAppListActivity")),
            new Intent().setComponent(new ComponentName("com.coloros.safecenter",
                    "com.coloros.safecenter.startupapp.StartupAppListActivity")), new Intent().setComponent(
            new ComponentName("com.oppo.safe", "com.oppo.safe.permission.startup.StartupAppListActivity")),
            new Intent().setComponent(new ComponentName("com.iqoo.secure",
                    "com.iqoo.secure.ui.phoneoptimize.AddWhiteListActivity")), new Intent().setComponent(
            new ComponentName("com.iqoo.secure", "com.iqoo.secure.ui.phoneoptimize.BgStartUpManager")),
            new Intent().setComponent(new ComponentName("com.vivo.permissionmanager",
                    "com.vivo.permissionmanager.activity.BgStartUpManagerActivity")), new Intent().setComponent(
            new ComponentName("com.asus.mobilemanager",
                    "com.asus.mobilemanager.entry.FunctionActivity")).setData(
            Uri.parse("mobilemanager://function/entry/AutoStart"))
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        enableAutoStart();
        startService(new Intent(MainActivity.this, VoiceRecognitionService.class));
    }

    private void enableAutoStart() {
        for (Intent intent : AUTO_START_INTENTS) {
            if (getPackageManager().resolveActivity(intent, PackageManager.MATCH_DEFAULT_ONLY) != null) {
                new Builder(this).title("Enable AutoStart")
                        .content("Please allow Speech to always run in the background,else our services can\'t be accessed when you are in distress")
                        .theme(Theme.LIGHT)
                        .positiveText("ALLOW")
                        .onPositive((dialog, which) -> {
                            try {
                                for (Intent intent1 : AUTO_START_INTENTS)
                                    if (getPackageManager().resolveActivity(intent1, PackageManager.MATCH_DEFAULT_ONLY) != null) {
                                        startActivity(intent1);
                                        break;
                                    }
                            } catch (Exception e) {
                                e.printStackTrace();
                            }
                        })
                        .show();
                break;
            }
        }
    }
}

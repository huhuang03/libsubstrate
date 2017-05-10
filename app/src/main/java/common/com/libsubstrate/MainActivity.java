package common.com.libsubstrate;

import android.app.Activity;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.widget.TextView;

/**
 * Created by york on 10/05/2017.
 */

public class MainActivity extends Activity {
    private TextView mTextView;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.actiivity_main);
        mTextView = (TextView) findViewById(R.id.text);
        mTextView.setText(stringFromJNI());

    }

    native String stringFromJNI();

    static {
        System.loadLibrary("demo");
    }

}

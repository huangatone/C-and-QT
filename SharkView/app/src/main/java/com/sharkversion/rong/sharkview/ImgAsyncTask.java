package com.sharkversion.rong.sharkview;

import android.os.AsyncTask;
import android.util.Log;
import android.widget.ListView;
import android.widget.Toast;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

/**
 * Created by rong on 7/17/17.
 */

public class ImgAsyncTask extends AsyncTask<String, Void, String> {

    private callBack callBack;
    protected String doInBackground(String... urls) {

        // params comes from the execute() call: params[0] is the url.
        try {
            return HttpGet(urls[0]);
        } catch (IOException e) {
            return "Unable to retrieve web page. URL may be invalid.";
        }
    }

    private String HttpGet(String myUrl) throws IOException {
        InputStream inputStream = null;
        String result = "";

        URL url = new URL(myUrl);

        // create HttpURLConnection
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();

        // make GET request to the given URL
        conn.connect();

        // receive response as inputStream
        inputStream = conn.getInputStream();

        // convert inputstream to string
        if(inputStream != null)
            result = convertInputStreamToString(inputStream);
        else
            result = "Did not work!";

        return result;
    }

    private static String convertInputStreamToString(InputStream inputStream) throws IOException{
        BufferedReader bufferedReader = new BufferedReader( new InputStreamReader(inputStream));
        String line = "";
        String result = "";
        while((line = bufferedReader.readLine()) != null)
            result += line;

        inputStream.close();
        return result;

    }
    // onPostExecute displays the results of the AsyncTask.

    protected void onPostExecute(String result) {
        //tvResult.setText(result);
        Log.v("Good", result);
        if (result != null) {
            try {
                JSONObject jsonObj = new JSONObject(result);
                // Getting JSON Array node
                JSONArray contacts = jsonObj.getJSONArray("Contacts");

                // looping through All Contacts
                for (int i = 0; i < contacts.length(); i++)
                {
                    JSONObject c = contacts.getJSONObject(i);

                    String name = c.getString("Name");
                    String pic = c.getString("pic");
                    String tel = c.getString("Tel");

                    callBack.setItem(name,pic,tel,c);
                    Log.e("haha", name + " " +  pic);
                }


            } catch (final JSONException e) {
                Log.e("haha", "Json parsing error: " + e.getMessage());

            }
        } else {
            Log.e("ooo", "Couldn't get json from server.");
        }


    }

    //给LoadTask添加设置回调的方法
    public void setCallBack(callBack callback){
        this.callBack = callback;
    }

    //设置回调借口
    public interface callBack{
        void setItem(String name,String pic,String tel,JSONObject c);
    }


}

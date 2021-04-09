package org.tty.test2.foundation;

import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.stream.JsonReader;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;
import java.util.stream.Collectors;

public class TestCaseManager {
    private static final String configPath = "/testCase.json";
    private static TestCaseManager gTestCaseManager = null;

    private void init() {

    }

    private TestCaseManager() {

    }


    public <T> List<T> loadTestCase(String scope, Class<T> instanceType) throws FileNotFoundException {
        Gson gson = new Gson();
        JsonReader reader = gson.newJsonReader(new FileReader(ResourceManager.getInstance().getRelativePath(configPath)));
        JsonObject jsonObject = gson.fromJson(reader, JsonObject.class);
        JsonObject scopeJsonObject = null;
        for (JsonElement object1 : (JsonArray) jsonObject.get("testCase")) {
            JsonObject currentScopeObject = ((JsonObject) object1);
            String currentScope = currentScopeObject.get("scope").getAsString();
            if (currentScope.equals(scope)){
                scopeJsonObject = currentScopeObject;
            }
        }

        assert scopeJsonObject != null;
        List<T> list = new ArrayList<>();

        JsonArray data = (JsonArray) scopeJsonObject.get("data");
        for (JsonElement object2: data) {
            list.add(gson.fromJson(object2, instanceType));
        }

        return list;
    }

    public <T> List<Object[]> loadTestCaseAndMap(String scope, Class<T> instanceType, Function<T, Object[]> function) throws FileNotFoundException {
        List<T> testCases = this.loadTestCase(scope, instanceType);
        return testCases.stream().map(function).collect(Collectors.toList());
    }

    public static TestCaseManager getInstance() {
        if (gTestCaseManager == null){
            gTestCaseManager = new TestCaseManager();
            gTestCaseManager.init();
        }
        return gTestCaseManager;
    }
}
